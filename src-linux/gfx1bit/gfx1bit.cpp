#include "gfx1bit.h"

#include <cstdlib>


#include "Adafruit_GFX.cpp"

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

#ifndef ARDUINO
void Print::println() {
	write('\n');
}

void Print::println(const char* text) {
	int i;
	for(i = 0; text[i] != 0; i++) {
		write(text[i]);
	}
	write('\n');
}

void Print::println(float f) {
	char buf[20];
	sprintf(buf, "%f\n", f);
	println(buf);
}
#endif



GFX1BIT::GFX1BIT(int16_t w, int16_t h): Adafruit_GFX(w, h), inverted(false) {
	size = w * h;
	bits = new uint8_t[size];
}

GFX1BIT::~GFX1BIT() {
	delete [] bits;
}

void GFX1BIT::drawPixel(int16_t x, int16_t y, uint16_t color) {
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
	uint32_t pixel = y * WIDTH + x;
	uint32_t offset = pixel / 8;
	uint8_t bit = 1 << (pixel % 8);
	//uint8_t byte = bits[offset];
	if (color) {
		// set bit
		bits[offset] |= bit;
	} else {
		// clear bit
		bits[offset] = bits[offset] & ~bit;
		//printf("byte %i "BYTETOBINARYPATTERN" => %i "BYTETOBINARYPATTERN"\n", byte, BYTETOBINARY(byte), bits[offset], BYTETOBINARY(bits[offset]));
	}
	//printf("drawPixel %i, %i, %i\n", x, y, color);
	//printf("bit %i "BYTETOBINARYPATTERN"\n", bit, BYTETOBINARY(bit));
	//printf("byte %i "BYTETOBINARYPATTERN" => %i "BYTETOBINARYPATTERN"\n", byte, BYTETOBINARY(byte), bits[offset], BYTETOBINARY(bits[offset]));
}


uint16_t GFX1BIT::readPixel(int16_t x, int16_t y) {
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return 0;
	uint32_t pixel = y * WIDTH + x;
	uint32_t offset = pixel / 8;
	if (inverted) {
		return (bits[offset] & (1 << (pixel % 8))) ? 0 : 1;
	} else {
		return (bits[offset] & (1 << (pixel % 8))) ? 1 : 0;
	}
}


void GFX1BIT::fillScreen(uint16_t color) {
	int i;
	if (color) {
		for(i = 0; i < size; i++) bits[i] = 0xff;
	} else {
		for(i = 0; i < size; i++) bits[i] = 0;
	}
}

void GFX1BIT::invertDisplay(boolean i) {
	inverted = i;
}




