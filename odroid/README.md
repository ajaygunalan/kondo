Connections for UART communication between ICS-UART (Servo) and Odroid XU4 shifter shield 

| ICS UART         | ODROID XU4 SHIFTER SHIELD                                |  
|:----------        |:-------------                                          |
| Tx(ICS UART)     |GPA0.0(#171)(XU4 SHIFTER SHIELD) = 16(wiringPi) = (6GPIO)|
| Rx(ICS UART)     |GPA0.1(#172)(XU4 SHIFTER SHIELD) = 15(wiringpi) = (8GPIO)|  
| IOREF(ICS UART)  |POWER(3.3v) (XU4 SHIFTER SHIELD)                         |  
| GND (ICS UART)   |GND (XU4 SHIFTER SHIELD)                                 |  
| EN (ICS UART)    |GPA0.2(#173)(XU4 SHIFTER SHIELD) = 1(wiringpi) = (12GPIO)|  

-----------
Before powering on the servo motors, ensure that the ICS UART converter is in the execution mode. The following link depicts the right configuration for execution mode. https://github.com/ajaygunalan/kondo/blob/master/docs/write.png

odroidxu4 password: odroid
