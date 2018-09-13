# pH / ORP adapter
This project describe a board for pH & ORP probe, designed for the for reef-pi project.
The design provide feature to manage probe, an signal amplifier, a A/D converter and a optoisolator circuit,
final interface is a I2C Addressable bus interface. 
Schematic & PCB are realized with Orcad 16, but pdf & gerber are available if you don't have license for them.

Optocouled system is not mandatory in Aquarium, but too often there are dispersion & leakage that can generate problem on mesaurement,so have probe interface optocpuled solve all problems.
A solder dip switch is provided on PCB to select the mode (gain) for pH probe or ORP probe, more then a 2 way disp switch offer 
4 different I2C address, so until 4 probes can teorically be connected on same I2C bus.
Assemble this circuit require a bit of experience on SMT component solderig process, personally i sold them by hand without problem,i will try to give some suggestion on how to step by step. PCB can be realized on-line by a large number of manufacturer, or shared from other user .

In this moment the project is under development, i'm wating for pcb prototype, so in short time will come material & informations.

