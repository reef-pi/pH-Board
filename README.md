# pH / ORP adapter
This project describes a board for pH & ORP probes, designed for the reef-pi project.
The design provides features to manage the probe, a signal amplifier, an A/D converter, and an optoisolator circuit.  The final interface is a I2C Addressable bus interface.
Schematic & PCB are created with Orcad 16, but pdf & gerber files are available if you don't have license for Orcad.

An optocoupled system is not mandatory in an Aquarium, but too often there are splashes & leaks that can cause problems on measurements.  An optocoupled interface solves these problems.
A solder dip switch is provided on the PCB to select the mode (gain) for pH probe or ORP probe.  There is also a 2 way dip switch that offers 4 different I2C addresses, so up to 4 probes can theoretically be connected on the same I2C bus.
Assembly of this circuit requires a bit of experience on SMT component soldering; personally I soldered them by hand without problem.  I will try to give some step by step suggestion on how to complete the soldering. The PCB can be ordered on-line by a large number of manufacturers, or shared from another user.

At this time, the project is under development.  I'm waiting for pcb prototypes, so additional material & information will come soon.

