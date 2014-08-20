all: img2bitarray

img2bitarray: img2bitarray.cpp
	g++ -o img2bitarray img2bitarray.cpp `sdl-config --libs --cflags` -lSDL_image -std=c++11

