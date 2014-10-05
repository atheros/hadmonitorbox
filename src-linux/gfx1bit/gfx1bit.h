#ifndef __GFX1BIT_H
#define __GFX1BIT_H



#ifndef ARDUINO
#include <stdint.h>
#include <cstdio>

#define HEX	1
#define DEC 2

class Print {
public:
	void println();
	void println(const char* text);
	void println(float f);
	void print(const char* text) { printf(text); };
	void println(unsigned int v, int i) {
		if (i == HEX) {
			printf("%x", v);
		} else if (i == DEC) {
			printf("%d", v);
		} else {
			printf("ERROR!!!! Invalid type: %i\n", i);
		}
	}
	
#if ARDUINO >= 100
  virtual size_t write(uint8_t) = 0;
#else
  virtual void   write(uint8_t) = 0;
#endif
};

typedef bool boolean;

#endif


#include "Adafruit_GFX.h"

class GFX1BIT: public Adafruit_GFX {
public:
	GFX1BIT(int16_t w, int16_t h);
	virtual ~GFX1BIT();
	
	virtual void drawPixel(int16_t x, int16_t y, uint16_t color);
	uint16_t readPixel(int16_t x, int16_t y);

	virtual void fillScreen(uint16_t color);
	virtual void invertDisplay(boolean i);
	
	void clearDisplay() { fillScreen(0); }
protected:
	uint8_t* bits;
	uint32_t size;
	bool inverted;
};


#endif /* !__GFX1BIT_H */
