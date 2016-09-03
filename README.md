# RCNinja

A long time ago, in a galaxy very, very close...

RCNINJA

---

On day one at the MRMCD 2016, my cousin and I decided to take an old car, strap an arduino and a tablet on it and implement something similar to TwitchPlaysXXX, from the principle.

# Setup/Idea

The electric car has an Arduino Micro and a Surface Pro 2 running Arch Linux strapped to it.

The Arduino Micro is basically just a motor controller. It's port 5 is connected to the signal wire of the motor controller, port 6 to the steering servo.

It is connected to the Surface Pro 2, which should broadcast the webcam to it's internal stream, but with an ASCII or face blurring filter, to protect people's privacy.

There should be an IRC bot running on it, sending serial commands to the arduino to control it. Decisions should be made using a voting system, which decides what to do in a given time interval.

Obviously, speed has to be kept low.
