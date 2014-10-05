GFX1BIT
=======

About
-----

This is a port of Adafruit_GFX to linux with 1bit image backend.

This code is needed for my project http://hackaday.io/project/2442-Hackaday-monitor-and-Lighting-Box


Status
------


### Test code

I used test code from one of Adafruit's OLED libraries. It turned out it had
some additional APIs I had to implement to make it work. I did skip however
all scrolling related functions.

The test code is using SDL as output, scalled 4x for better view.


### Inverted display

The behavior of this feature is not documented at all, so I have no idea how
this works. I currently tried to simply invert readPixel, so the output is
inverted.


### Print class

Adafruit_GFX uses Print class interface. I only implemented the functions
needed to make the example work. If I have some time, I'll implemenmt more.


License
-------

GFX1BIT code was written by Przemysław Grzywacz <nexather@gmail.com>

This code is licensed under the same license as Adafruit_GFX.

See license.txt

