#led in pin 0(17) 
#gpio mode 0 out

#pin (1)18 (ISR)
gpio mode 1 in
gpio mode 1 up
gpio edge 1 falling

#pin (4)23 (ISR)
gpio mode 4 in
gpio mode 4 up
gpio edge 4 falling

#load i2c kernel module
gpio load i2c

#export the pins
gpio export 17 out
gpio export 18 in
gpio export 23 in



