CONNECTIONS FOR UART COMMUNICATION BETWEEN ICS-UART (SERVO) AND ODROID XU4 SHIFTER SHIELD 

| ICS UART         | ODROID XU4 SHIFTER SHIELD                                |  
|----------        |:-------------:                                           |
| Tx(ICS UART)     | GPA0.1(#172)(XU4 SHIFTER SHIELD) = 15(wiringPi) = (8GPIO)|
| Rx(ICS UART)     | GPA0.0(#171)(XU4 SHIFTER SHIELD) = 16(wiringpi) = (6GPIO)|  
| IOREF(ICS UART)  | POWER(3.3v) (XU4 SHIFTER SHIELD)                         |  
| GND (ICS UART)   | GND (XU4 SHIFTER SHIELD)                                 |  
| EN (ICS UART)    | GPA0.3(#174)(XU4 SHIFTER SHIELD) = 0(wiringpi) = (11GPIO)|  

-----------
   
