Connections for UART communication between ICS-UART (Servo) and Odroid XU4 shifter shield 

| ICS UART         | ODROID XU4 SHIFTER SHIELD                                |  
|:----------       |:-------------                                          |
| Tx               |GPA0.0(#171) = 16(wiringPi) = (6GPIO)|
| Rx(              |GPA0.1(#172) = 15(wiringpi) = (8GPIO)|  
| IOREF            |POWER(3.3v)                          |  
| GND              |GND                                  |  
| EN               |GPA0.2(#173) = 1(wiringpi) = (12GPIO)|  

-----------
Before powering on the servo motors, ensure that the ICS UART converter is in the execution mode. The following link depicts the right configuration for execution mode. https://github.com/ajaygunalan/kondo/blob/master/docs/write.png

odroid xu-4 password: `odroid`

[pinout diagram](https://wiki.odroid.com/odroid-xu4/hardware/expansion_connectors#gpio_map_for_wiringpi_library_shifter-shield_40_pin)
