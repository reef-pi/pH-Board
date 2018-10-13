# pH / ORP adapter
This project describes a board for pH & ORP probes, designed for the reef-pi project.
The design provides features to manage the probe, a signal amplifier, an A/D converter, and an optoisolator circuit.  The final interface is a I2C Addressable bus interface.
Schematic & PCB are created with Orcad 16, but pdf & gerber files are available if you don't have license for Orcad.

An optocoupled system is not mandatory in an Aquarium, but too often there are splashes & leaks that can cause problems on measurements.  An optocoupled interface solves these problems.
A solder dip switch is provided on the PCB to select the mode (gain) for pH probe or ORP probe.  There is also a 2 way dip switch that offers 4 different I2C addresses, so up to 4 probes can theoretically be connected on the same I2C bus.
Assembly of this circuit requires a bit of experience on SMT component soldering; personally I soldered them by hand without problem.  I will try to give some step by step suggestion on how to complete the soldering. The PCB can be ordered on-line by a large number of manufacturers, or shared from another user.

Assembly
Passive components are style 0603,small but not smallest, in any case to solder the componenents are necessary SMT welder, tin solder for SMT, SMT tweezers and most important a big lens or a binocular stereoscope, if you don't have similar tool i suggest find some one have it, obviously is required also a confidence with the process.
When soldering process is finished be sure to remove all short circuit and excess of tin, using a copper braid it's good method.
Be sure to clean accuratley the board from flux, specially around U1 & J2, it's special and critical opamp, no flux must be on this ic pins, or you will have problem with pH probe.
J1 must be soldered closign the circuit on pH poistion or ORP position, depend from adapter usage.

![connections picture](https://i.imgur.com/EgzPYYY.jpg)

Address, basically the board has as address 0x40, up to 4 adapter can be used on same I2c bus, dip switch SW1 need to be set in according with software control system.

Address table, SW1		
Slide 1	Slide 2	Address
off	    off	    0x40
on	    off	    0x41
off	    on	    0x42
on	    on	    0x43

Testing
Connect the board to RPI3, gnd (pin 39) +5V (pin 2) SDA1 (pin3) SCL1 (pin 5), be sure the address is 0x40 (SW1 off),be sure the I2C is enabled on Pi3, run i2cdetect (i2cdetect -y 1), the program must find the device at address 0x40, if not check the solder / connections. For a how to i suggest search with google "pi3 i2cdetect" or something like that, you find a lot of instructions.

![connections picture](https://imgur.com/1BIG9ph.jpg)

When you are sure the I2C channel is working run the program provided for test named "sample". 
The program read the AD converter very quicky, connect the pH probe and place it in buffer solution, like pH4 or pH 10, correct value will be around 20.000 digit at pH 4 and -20.000 at pH 10.
If you read 32768 means out of range, something of wrong happen on analog part.

Software sequence :
Base address 0x40
Init sequence :
 write 0x40,0x06  //SW reset 
 write 0x40,0x40,0x06;  //set config reister continuos conversion, 90SPS
 write 0x40,0x08;   // start conversione
 
 loop to read value periodically:
 write 0x40,0x10 then read two bytes
 that's all, enjoy.
 
 
 
