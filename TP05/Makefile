CFLAGS = -Wall -Wextra -pedantic -std=c99 -g -O0
CMEM = -fsanitize=address
CLINK = -lm

build: stb_image.h stb_image_write.h seam_carving.h seam_carving.c
	gcc $(CFLAGS) seam_carving.c -o seam_carving $(CLINK)

secure: stb_image.h stb_image_write.h seam_carving.h seam_carving.c 
	gcc $(CFLAGS) $(CMEM) seam_carving.c -o seam_carv_secure $(CLINK)

run: seam_carving
	./seam_carving

runs: seam_carv_secure
	./seam_carv_secure

all: build run

alls: secure runs

clean:
	rm seam_carving
	rm seam_carv_secure
