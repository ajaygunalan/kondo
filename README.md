 Check the [Wiki Page](https://github.com/ajaygunalan/kondo/wiki/Kondo-Servo-Series---Wiki) for detailed information.

*kondo.ino* runs the servo without any external library.

*spine.ino* needs [Kondo ICS Arduino Library](https://kondo-robot.com/faq/ics-library-a2) to run.
It contain values within **joint limit** for the spine.

[Testing of leg](https://www.youtube.com/playlist?list=PL-dIBMwXD0RVGOw8f2vEzI9Z0xxggWJjg)

**Nominal Working of Kondo**


1. When you connect a servo initially, red led will flash brighlty, indicating the servo is connected,

2. During execution the led will blink (with less intensity than the former case.)

3. Alwayd disconnect the servo while dumping the binaries into the controller board.


