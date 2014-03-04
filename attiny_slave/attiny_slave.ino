/* ATtiny85 as an I2C Master   Ex2        BroHogan                           1/21/11
 * I2C master reading DS1621 temperature sensor. Display to I2C GPIO LED.
 * SETUP:
 * ATtiny Pin 1 = (RESET) N/U                      ATtiny Pin 2 = (D3) N/U
 * ATtiny Pin 3 = (D4) to LED1                     ATtiny Pin 4 = GND
 * ATtiny Pin 5 = SDA on DS1621  & GPIO            ATtiny Pin 6 = (D1) to LED2
 * ATtiny Pin 7 = SCK on DS1621  & GPIO            ATtiny Pin 8 = VCC (2.7-5.5V)
 * NOTE! - It's very important to use pullups on the SDA & SCL lines!
 * DS1621 wired per data sheet. This ex assumes A0-A2 are set LOW for an addeess of 0x48
 * PCA8574A GPIO was used wired per instructions in "info" folder in the LiquidCrystal_I2C lib.
 * This ex assumes A0-A2 are set HIGH for an addeess of 0x3F
 * LiquidCrystal_I2C lib was modified for ATtiny - on Playground with TinyWireM lib.
 * TinyWireM USAGE & CREDITS: - see TinyWireM.h
 */

#define DEBUG

#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,1); // RX, TX

#include "TinyWireM.h"                  // I2C Master lib for ATTinys which use USI
#include "LiquidCrystal_I2C.h"          // for LCD w/ GPIO MODIFIED for the ATtiny85

#define GPIO_ADDR     0x3F             // (PCA8574A A0-A2 @5V) typ. A0-A3 Gnd 0x20 / 0x38 for A

LiquidCrystal_I2C lcd(GPIO_ADDR,20,4);  // set address & 16 chars / 2 lines

char buf[12];

void setup(){

}

int sIn;
int i=0;

void loop(){
 
 // mySerial.println("test");
 
  if (mySerial.available()>0){
    buf[i]= mySerial.read(); 
   
   lcd.println(buf); 
    if (int(buf[i])==13 || int(buf[i])==10 ){ //If Carriage return has been reached
      mySerial.println(buf);
      for(int x=0;x<=10;x++){
        buf[x]=' ';
      }
      
      i=0; //start over again
  
    } //if enter
    i++; 
  }
    
}
