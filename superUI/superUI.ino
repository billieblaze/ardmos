/*
  This is a remix of Alex Leone TLC5940Mux library by bill berzinskas
  
  this library will use a shift register / darlington array rather then the 3:8 converter for row scanning
  and will also clock in buttons from the UI.  Hopefully this can all share a single clock
  I will use this to power a 16x8 sparkfun rgb button pad
  
  
*/

#define  NUM_TLCS  3
#define  NUM_ROWS  2
#include "Tlc5940Mux.h"

volatile uint8_t isShifting;
uint8_t shiftRow;

ISR(TIMER1_OVF_vect)
{
  if (!isShifting) {
    sei();
    disable_XLAT_pulses();
    isShifting = 1;
    TlcMux_shiftRow(shiftRow);
    shiftRow++;
    enable_XLAT_pulses();
    isShifting = 0;
  }
}

void setup()
{
  TlcMux_init();
  
}

void loop()
{
 
}
