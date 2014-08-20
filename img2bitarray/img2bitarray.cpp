/*
 * Copyright (c) 2014 Przemysław Grzywacz <nexather@gmail.com>
 * This file is part of xbrzscale.
 *
 * xbrzscale is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdio>
#include <cstdint>
#include <cstring>

#include "SDL.h"
#include "SDL_image.h"


inline Uint32 SDL_GetPixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "usage: img2bitarray input_image var_name\n");
		return 1;
	}

	const char* in_file = argv[1];
	const char* var_name = argv[2];
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_Surface* src_img = IMG_Load(in_file);
	if (!src_img) {
		fprintf(stderr, "Failed to load source image '%s': %s\n", in_file, IMG_GetError());
		return 1;
	}
	
//	displayImage(src_img, "Source image");

	int src_width = src_img->w;
	int src_height = src_img->h;

	uint8_t buffer = 0;
	
	int buffer_index = 0;
	int x, y, offset;
	Uint8 r, g, b, a;
	uint32_t c;

	offset = 0;
	
	printf("static const uint8_t %s[] = {\n\t", var_name);
	for(y = 0; y < src_img->h; y++) {
		for(x = 0; x < src_img->w; x++) {
			c = SDL_GetPixel(src_img, x, y);
			SDL_GetRGBA(c, src_img->format, &r, &g, &b, &a);
			
			buffer |= ((r || g || b) && a) << buffer_index;
			buffer_index--;
			if (buffer_index < 0) {
				buffer_index = 7;
				if (offset % 128 == 0 && offset > 0) {
					printf(",\n\t");
				} else if (offset > 0) {
					printf(", ");
				}
				printf("0x%02x", buffer);
				buffer = 0;
			}
			offset++;
		}
//		fprintf(stdout, "\n");
	}
	printf("\n}; /* end of %s image */\n\n", var_name);
	SDL_FreeSurface(src_img);

	SDL_Quit();
	return 0;
}
