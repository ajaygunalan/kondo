# Check on which port uart is activated b:
 
	ls -l /dev | grep serial

serial0 is TX and RX 

#Give Permission to the above port:
 
	sudo chmod 777  /dev/ttyS0


