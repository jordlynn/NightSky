NightSky
========
This program is finished and runs on an arduino.
Be aware when using this to the pins used and what is going where if you need to know I can send you hardware layouts so you don't burn out LEDs/arduinos. Using simple NFC you can send messages to the arduino which in turn will turn on a string of LEDs.

Required software/hardware
==========================
- arduino
- LED(s)
- hardware (resistors, diodes, ect. to run LED(s)
- Android phone with my NFC android app, or any NFC device for limited capabilities
- Adafruit's NFC shield library

What's up with the code?
========================
Currently this program will not work with-out Adafruit's NFC library for the arduino, additionally without the version I've edited to work with either any standard device or you can get additional functionalities using an Android powered NFC device. As of this writing there isn't a lot of devices out there so right now I will only guarentee this will work with Nexus devices, but other Android devices will probably do.

I am not going to upload the original Adafruit library for copyright reasons, and it won't work with the LEDs. But an edited version will by up called Readinglights so grab that one and make sure it's included. There's a lot of Adafruit's code in there and a chunk of my own.

BUT if you do end up getting the adafruit library and want to edit it yourself for whatever reason you have, the areas you'll focus on are the "readPassiveTargetID()" function. That's where an interupt will happen and you can loop out and start executing your own code, the function following that one hadles the encyption and data which I used for android but I left untouch for the public because you can permanently lock/format your card with the calls in that function.
