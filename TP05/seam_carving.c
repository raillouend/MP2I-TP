#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STBI_NO_FAILURE_STRINGS
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"
#include "stb_image_write.h"

#include "seam_carving.h"

image *image_load(char *filename){
    int w, h, channels;
    uint8_t *data = stbi_load(filename, &w, &h, &channels, 0);
    if (!data) {
        fprintf(stderr, "Erreur de lecture.\n");
        stbi_failure_reason();
        exit(EXIT_FAILURE);
    }
    if (channels != 1){
        fprintf(stdout, "Pas une image en niveaux de gris.\n");
        exit(EXIT_FAILURE);
    }
    image *im = image_new(h, w);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            im->at[i][j] = data[j + i * w];
        }
    }
    free(data);
    return im;
}

void image_save(image *im, char *filename){
    int h = im->h;
    int w = im->w;
    int stride_length = w;
    uint8_t *data = malloc(w * h * sizeof(uint8_t));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            data[j + i * w] = im->at[i][j];
        }
    }
    if (!stbi_write_png(filename, w, h, 1, data, stride_length)){
        fprintf(stderr, "Erreur d'écriture.\n");
        image_delete(im);
        free(data);
        exit(EXIT_FAILURE);
    }
    free(data);
}

image *image_new(int h, int w)
{
    image *im = malloc(sizeof(image));
    im->at=malloc(h * sizeof(uint8_t*));
    
    im->h = h;
    im->w = w;
	
    for (int i = 0; i < h; i++) 
    {
       im->at[i]= malloc(w * sizeof(uint8_t));
    }

    return im;
}
void image_delete(image *im)
{
    for(int i = 0; i < im->h; i++)
    {
    	free(im->at[i]);
    }
    
    free(im->at);	
    free(im);
} 

void invert(image *im)
{
    for (int i = 0; i < im->h; i++) 
    {
    	for(int j=0; j < im->w; j++)
    	{
    	 	im->at[i][j] = 255 - im->at[i][j];
    	}
    }
}

void binarize(image *im) {
	for (int i = 0; i < im->h; i++) {
		for(int j=0; j < im->w; j++) {
			if (im->at[i][j] < 128) {
				im->at[i][j] = 0;
			} else {
				im->at[i][j] = 255;
			}
		}
	}
}

void flip_horizontal(image *im) {
	int hauteur = im->h;
	int largeur = im->w;
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < (largeur+1)/2; j++) {
			int transfert = im->at[i][j];
			im->at[i][j] = im->at[i][largeur-j];
			im->at[i][largeur-j] = transfert;
		}
	}
}




energy *energy_new(int h, int w) {
	energy* e = (energy*) malloc(sizeof(energy));
	double** at = (double**) malloc(h*sizeof(double*));
	
	for (int i = 0; i < h; i++) {
		at[i] = (double*) malloc(w*sizeof(double));
	}

	e->at = at;
	e->h = h;
	e->w = w;

	return e;
}

void energy_delete(energy *e) {
	for (int i = 0; i < e->h; i++) {
		free(e->at[i]);
	}
	free(e->at);
	free(e);
}


void compute_energy(image *im, energy *e) {
	uint8_t** at = im->at;
	for (int i = 0; i < im->h; i++) {
		int ib = i < im->h - 1 ? i+1 : i;
		int it = i > 0 ? i-1 : i;
		for (int j =0; j < im->w; j++) {
			int jr = j < im->w -1 ? j+1 : j;
			int jt = j > 0 ? j-1 : j;
			
			double dx = (double) (at[i][jr]-at[i][jt])/(jr-jt); 
			double dy = (double) (at[ib][j]-at[it][j])/(ib-it);

			e->at[i][j] = fabs(dx) + fabs(dy); // utilisation de fabs car coder la valeur absolue prendrais trop de temps
		}
	}
}

image *energy_to_image(energy *e) {
	double min = e->at[0][0];
	double max = e->at[0][0];

	for (int i = 0; i < e->h; i++) {
		for (int j = 0; j < e->w; j++) {
			if (min > e->at[i][j]) {
				min = e->at[i][j];
			} else if (max < e->at[i][j]) {
				max = e->at[i][j];
			}
		}
	}

	image* im = image_new(e->h, e->w);
	for (int i = 0; i < e->h; i++) {
		for (int j = 0; j < e->w; j++) {
			im->at[i][j] = (uint8_t) (255*(e->at[i][j]-min)/(max-min));
		}
	}

	return im;

}



void remove_pixel(uint8_t *line, double *e, int w) {
	int min = 0;
	for (int i = 0; i < w; i++) {
		if (e[i] < e[min]) {
			min = i;
		}
	}
	
	for (int i = min; i < w-1; i++) {
		line[i] = line[i+1];
		e[i] = e[i+1];
	}
}


void reduce_one_pixel(image *im, energy *e) {
	for (int i = 0; i < im->h; i++) {
		remove_pixel(im->at[i], e->at[i], im->w);
	}
	im->w -= 1;
	e->w -= 1;
}

void reduce_pixels(image *im, int n) {
	energy* e = energy_new(im->h, im->w);
	compute_energy(im, e);
	for (int i = 0; i < n; i++) {
		reduce_one_pixel(im, e);
	}

	energy_delete(e);
}


int best_column(energy *e) {
	double min;
	int mini = 0;
	double somme = 0;
	// Somme de la première colonne
	for (int i = 0; i < e->h; i++) {
		somme += e->at[i][0];
	}
	min = somme;
	
	// Cherche le minimum
	for (int i = 1; i < e->w; i++) {
		somme = 0;
		for (int j = 0; j < e->h; j++) {
			somme += e->at[j][i];
		}
		if (somme < min) {
			min = somme;
			mini = i;
		}
	}

	return mini;
}

void reduce_one_column(image *im, energy *e) {
	for (int i = best_column(e); i < im->w-1; i++) {
		for (int j = 0; j < im->h; j++) {
			im->at[j][i] = im->at[j][i+1];
			e->at[j][i] = e->at[j][i+1];
		}
	}
	im->w -= 1;
	e->w -= 1;
}

void reduce_columns(image *im, int n) {
	energy* e = energy_new(im->h, im->w);
	compute_energy(im, e);
	
	for (int i = 0; i < n; i++) {
		reduce_one_column(im, e);
	}

	energy_delete(e);
}

void energy_min_path(energy *e) {
	for (int i = 1; i < e->h; i++) {
		// Premier pixel
		double e0 = 0;
		double e1 = e->at[i-1][0];
		double e2 = e->at[i-1][1];
		e->at[i][0] += e1 < e2 ? e1 : e2;
		for (int j = 1; j < e->w-1; j++) {
			e0 = e->at[i-1][j-1];
			e1 = e->at[i-1][j];
			e2 = e->at[i-1][j+1];

			e->at[i][j] += e1 < e2 ? (e1 < e0 ? e1 : e0) : (e2 < e0 ? e2 : e0);
		}
		e0 = e->at[i-1][e->w-2];
		e1 = e->at[i-1][e->w-1];
		e->at[i][e->w-1] += e0 < e1 ? e0 : e1;
	}
}


path *path_new(int n) {
	path* p = (path*) malloc(sizeof(path));
	p->at = (int*) malloc(n*sizeof(int));
	p->size = n;

	return p;
}

void path_delete(path *p) {
	free(p->at);
	free(p);
}

void compute_min_path(energy *e, path *p) {
	int min = 0;

	// Dernière ligne
	for (int i = 1; i < e->w; i++) {
		if (e->at[e->h-1][i] < e->at[e->h-1][min]) {
			min = i;
		}
	}
	
	p->at[e->h-1] = min;
	
	// Lignes suivantes
	for (int i = e->h-1; i >= 1; i--) {
		int precedent = p->at[i];
		double e0; 
		double e1;
		double e2; 
		if (precedent == 0) {
			e1 = e->at[i-1][precedent];
			e2 = e->at[i-1][precedent+1]; 
			p->at[i-1] = e1 < e2 ? precedent : precedent+1;
		} else if (precedent == e->w-1) {
			e0 = e->at[i-1][precedent-1]; 
			e1 = e->at[i-1][precedent];
			p->at[i-1] = e0 < e1 ? precedent-1 : precedent;
		} else {
			e0 = e->at[i-1][precedent-1]; 
			e1 = e->at[i-1][precedent];
			e2 = e->at[i-1][precedent+1]; 
			p->at[i-1] = e0 < e1 ? (e0 < e2 ? precedent-1 : precedent+1) : (e1 < e2 ? precedent : precedent+1);
		}
	}
}

void reduce_seam_carving(image *im, int n) {
	energy* e = energy_new(im->h, im->w);

	for (int i = 0; i < n; i++) {
		path* p = path_new(im->h);
		compute_energy(im, e);
		energy_min_path(e);
		compute_min_path(e, p);

		for (int j = 0; j < im->h; j++) {
			for (int k = p->at[j]; k < e->w-1; k++) {
				im->at[j][k] = im->at[j][k+1];
			}
		}
		e->w -= 1;
		im->w -= 1;
		path_delete(p);
	}
	energy_delete(e);
}



int main(int argc, char *argv[]) {
	if (argc < 3){
		printf("Fournir le fichier d'entrée et de sortie.\n");
		exit(EXIT_FAILURE);
	}
	char *f_in = argv[1];
	char *f_out = argv[2];
	image *im = image_load(f_in);

	// Do some processing here
	reduce_seam_carving(im, 100);

	image_save(im, f_out);

    	image_delete(im);
	return 0;
}
