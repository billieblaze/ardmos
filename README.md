ardmos
======

an Arduino Musical Device Operating System

So, I've got this idea for a totally modular synth / controller / whatever environment.   A master ATMega runs an event driven framework and manages any time sensitive operations.   It delegates tasks to a series of "modules" like Digitial IO, Analog IO, MIDI, Matrix LED, etc. Rather then connecting the master straight to a shift register chain, or some other peripherals,  the functionality would be controlled by an i2c ATtiny slave.   

Why would I want to do this?  Well, I've got several musical related projects (Midi sequencer, wavetable oscillator, midi controllers) and I'd like to reign in the codebase a little.  Each project has many similarities that could easily be abstracted.  I feel the advantages are huge for a few reasons:   

1) UI and other long running tasks don't tie up the more crucial time sensitive bits
2) Modules could become their own standalone gizmos or could be interconnected in almost limitless ways

As with many of my projects, I will be standing on the shoulders of giants and utilizing well documented open source libraries and tools and will keep track of that info here as well. 

Proposed Core functionality:
 - Event Driven framework or RTOS
 - MIDI IO with thru / clock sync / clock gen
 - Bootload slaves via I2c using TinySafeBoot (http://jtxp.org/tech/tinysafeboot_en.htm)
 - Allow configuration of slave address / role 

Modules will have an address and a corresponding role.   A simple messaging setup should allow a few bits
to delegate any task and value from the core to the slave.  

Proposed modules for V1:

- Analog In  (rot ary pots, audio, cv, etc)  -- todo: select mux
- Analog Out  (i2c dac, audio / cv)   -- Max525/5250? 
- Digital In (button / encoders)  - 595 shift register maybe, not a fan tho, would like a key decoder w/ interrupts
- Digital out (led, trigger, etc) - could use SR, meh..   Using TLC5940 for Matrix, why not do that? 
- RGB LED Matrix (standard matrix or sparkfun rgb button pad) - TLC5940 and 164/165 for keypad? or again, key decoder  
- Keypad decoding - same
- - I2c text and graphical lcds - these are probably going to wind up being attached to the master, but i've had i2c led related problems in some of my other sketches




