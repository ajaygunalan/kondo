#Kondo KRS 60003 R2 HV with RPI3 (Model B + & Raspbian OS)  


### Check on which port uart is activated by:
 
	ls -l /dev | grep serial

serial0 is TX and RX 

### Give Permission to the above port:
 
	sudo chmod 777  /dev/ttyS0


