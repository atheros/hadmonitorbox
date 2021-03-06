/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Przemysław Grzywacz
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
// This #include statement was automatically added by the Spark IDE.
#include "Adafruit_SSD1306/Adafruit_SSD1306.h"

// This #include statement was automatically added by the Spark IDE.
#include "Adafruit_Thermal/Adafruit_Thermal.h"

/* Uncomment this block to use hardware SPI*/
// If using software SPI (the default case):
#define OLED_MOSI   D2
#define OLED_CLK    D3
#define OLED_DC     D4
#define OLED_CS     D5
#define OLED_RESET  D6
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/*
// use hardware SPI
#define OLED_DC     D3
#define OLED_CS     D4
#define OLED_RESET  D5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
*/


Adafruit_Thermal printer;


#define CLOUD_W 128
#define CLOUD_H 128

static const uint8_t cloud[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0xff, 0xff, 0xfc, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x1f, 0xc0, 0x03, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0x80, 0x0f, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0xfc, 0x01, 0xff, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xfc, 0x00, 0x00,
	0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfe, 0x01, 0xff, 0xfe, 0x00, 0x00,
	0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xff, 0xfe, 0x00, 0x00,
	0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xfe, 0x00, 0x00,
	0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xfe, 0x00, 0x00,
	0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xfe, 0x00, 0x00,
	0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfe, 0x00, 0x00,
	0x00, 0xff, 0xfc, 0x01, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xff, 0x87, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xbf, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfe, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00,
	0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xc0,
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xe0,
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfc,
	0x00, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe,
	0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff,
	0x00, 0x07, 0xff, 0xf8, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x7f, 0xff,
	0x80, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff,
	0xc0, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff,
	0xc0, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff,
	0xe0, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
	0xf0, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f,
	0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
	0xf8, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
	0xf8, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
	0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
	0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
	0xfc, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
	0xfd, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
	0xfe, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
	0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
	0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
	0xfc, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
	0xfc, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
	0xf8, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
	0xf8, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f,
	0xf0, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
	0xf0, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff,
	0xe0, 0x0f, 0xff, 0x80, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x07, 0xff,
	0xc0, 0x0f, 0xff, 0xe0, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x1f, 0xff,
	0xc0, 0x07, 0xff, 0xf8, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x7f, 0xff,
	0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfc,
	0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf8,
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xe0,
	0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xc0,
	0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}; /* end of cloud image */

#define HACKADAY_LOGO_W 54
#define HACKADAY_LOGO_H 50

static const uint8_t hackaday_logo[] = {
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff,
	0xff, 0x0f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xe3, 0xff,
	0xff, 0xe1, 0xff, 0xff, 0xff, 0x87, 0xff, 0xbf, 0x07, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0x78, 0x1f,
	0xff, 0xff, 0xf8, 0x1e, 0x7c, 0xc0, 0x3f, 0xff, 0xff, 0xc0, 0x33, 0xf0, 0x00, 0x7f, 0xff, 0xfe,
	0x00, 0x0f, 0xe0, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xc0, 0x00, 0xff, 0xff, 0x80, 0x03, 0xff,
	0xf8, 0x01, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0x00, 0xf8, 0x0f, 0xff, 0xff, 0xf0, 0xe0,
	0x00, 0x70, 0x7f, 0xff, 0xff, 0xe7, 0x00, 0x00, 0xe7, 0xff, 0xff, 0xff, 0xd8, 0x00, 0x01, 0xbf,
	0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff,
	0xf8, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x0f, 0x81,
	0xf1, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0x8f, 0xe3, 0xff, 0xff, 0xff, 0xf1, 0xfe, 0x7f, 0x8f, 0xff,
	0xff, 0xff, 0xc7, 0xf9, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0x1f, 0x81, 0xf8, 0xff, 0xff, 0xff, 0xfc,
	0x78, 0x01, 0xe3, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0x03, 0x0f, 0xff, 0xff, 0xff, 0xe0, 0x06, 0x00,
	0x7f, 0xff, 0xff, 0xff, 0x80, 0x18, 0x01, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xf0, 0x0f, 0xff, 0xff,
	0xff, 0xcc, 0x03, 0xc0, 0x33, 0xff, 0xff, 0xfe, 0x38, 0x09, 0x01, 0xc7, 0xff, 0xff, 0xf0, 0x70,
	0x00, 0x0e, 0x07, 0xff, 0xf0, 0x00, 0xe0, 0x00, 0x70, 0x00, 0xff, 0x80, 0x01, 0x86, 0x61, 0xc0,
	0x01, 0xfc, 0x00, 0x1e, 0x19, 0x87, 0x80, 0x03, 0xf3, 0x00, 0xfc, 0xe6, 0x3f, 0x00, 0xcf, 0xde,
	0x07, 0xff, 0xff, 0xfe, 0x07, 0xbe, 0xfc, 0x1f, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xf8, 0x7f, 0xff,
	0xff, 0xe1, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xfe, 0x3f,
	0xff, 0xfe, 0x3f, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff
}; /* end of hackaday_logo image */


void setup()   {
	// set timezone GMT+2
    Time.zone(2);
    
    Serial.begin(9600);
    
    // init printer
    Serial1.begin(19200);
    printer.begin(&Serial1, 60);
    
    // init display
    display.begin(SSD1306_SWITCHCAPVCC);
    display.clearDisplay();
    
    // display we are printing a weather forecast
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Weather forecast!");
    display.println("City:");
    display.setTextSize(2);
    display.setCursor(128 / 2 -(12 * 6) / 2, 32);
    display.println("WARSAW");
    display.display();

    // wake the printer
    printer.wake();
    printer.setDefault();
    
    // print the forecast
    printer.setSize('S');     // Set type size, accepts 'S', 'M', 'L'
    printer.println("20 August 2014");
    
    printer.setSize('L');     // Set type size, accepts 'S', 'M', 'L'
    printer.println("Warsaw");
    
    printer.printBitmap(CLOUD_W, CLOUD_H, cloud);
    
    printer.setSize('M');     // Set type size, accepts 'S', 'M', 'L'
    printer.print(" 8:00 - 20.0"); printer.write(0xf8); printer.println("C, wind 2.72m/s");
    printer.print("12:00 - 23.2"); printer.write(0xf8); printer.println("C, wind 3.10m/s");
    printer.print("16:00 - 19.5"); printer.write(0xf8); printer.println("C, wind 2.72m/s");
    printer.print("20:00 - 17.0"); printer.write(0xf8); printer.println("C, wind 2.72m/s");
    
    printer.feedRows(1);
    
    
    // display information there is a new HACK!
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(128 / 2 - (12 * 9) / 2, 16);
    display.println("NEW HACK!");
    display.display();
    
    // print info about new hack
    printer.setSize('S');
    printer.println("New Hackaday.com article!");

    //printer.printBitmap(HACKADAY_LOGO_W, HACKADAY_LOGO_H, hackaday_logo);
    printer.println("> Biometric Secured Golfcart Allows For Keyless Start");
    printer.feed(2);
    printer.sleep();
    
    // animate the information
    display.invertDisplay(true);
    delay(1000); 
    display.invertDisplay(false);
    delay(1000); 
    display.invertDisplay(true);
    delay(1000); 
    display.invertDisplay(false);
    delay(1000); 
    
}


char time_buf[6];
char date_buf[11];
void loop() {
    
    // animate the : between hour and minute every second
    if (Time.second() % 2 == 0) {
        sprintf(time_buf, "%02i:%02i", Time.hour(), Time.minute());
    } else {
        sprintf(time_buf, "%02i %02i", Time.hour(), Time.minute());
    }
    sprintf(date_buf, "%04i-%02i-%02i", Time.year(), Time.month(), Time.day());
    
    // display time
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(4);
    display.setCursor(128 / 2 - (23 * 5) / 2, 8);
    display.print(time_buf);
    
    // display date
    display.setTextSize(2);
    display.setCursor(128 / 2 - (12 * 10) / 2, 64 - 16);
    display.print(date_buf);
    
    display.display();
    
    delay(200);
}

