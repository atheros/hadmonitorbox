Hackaday monitor and Lighting Box
=================================

About
-----

Never know when a new exciting post arrives to Hackaday.com? With Hackaday
monitor & Lighting Box you will know moments after it gets published!
Need a weather forecast? Not a problem, you'll have it printed and waiting
for you as soon as you wake up. Did I mention it will be stuffed with RGB
LEDs to lighten up the mood? 

This repository will hold all documents, designs and sourcecode of the project.

All project details are hosted on Hackaday.io: http://hackaday.io/project/2442-Hackaday-monitor-and-Lighting-Box


License
-------

The code is published under MIT License unless written otherwise.


Install
-------

You need to setup your environment for offline Spark Core coding. This is done
by following offical instructions:
https://github.com/spark/core-firmware/blob/master/README.md

When you're done, go to the `core-firmware/src` directory and execute
script from `hadmonitor/linksrc.sh`. This script will link source code
directory to Spark Core firmware directory and add them to makefiles.
This was tested only on linux.

Once done, you can test the build by going to `core-firmware/build`
and typing `make`.


External software
-----------------

Bellow is a list of additional external software used:
- Adafruit_SSD1306 (Spark Core port)
- Adafruit_GFX (Spark Core port)
- Adafruit_Thermal (Spark Core port)
- GFX1BIT (Adafruit_GFX 1bit port to Linux)


Branches
--------

TheHackadayPrize-demo1 - code used to record demo1 video



