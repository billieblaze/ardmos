#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#define CLK 8 
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);

int BLACK = matrix.Color333(0,0,0);
int GREEN = matrix.Color333(0,10, 0);
int ORANGE = matrix.Color333(10,10,0);
int RED = matrix.Color333(10,0,0);

byte array[16] =    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int i, j, k, r;

void setup ()
{
  matrix.begin();
  Serial.begin(9600);
  delay(500);
}

void loop()
{
  if (Serial.available()){ 
    if (Serial.read() == 0xff) {
      for (i = 0; i < 16; i++) {
        array[i] = Serial.read();
      }
    }  
  }
    //switch case statement
    for (j = 0; j < 16; j++) {
 
        switch (array[j]) {
          case 0:
            matrix.drawLine(2 * j, 0, 2 * j, 15, BLACK);
            break;
        case 1:
            matrix.drawLine(2 * j, 0, 2 * j, 15, BLACK);
            matrix.drawPixel(2 * j, 15, GREEN);
            break;
          case 2:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 14, GREEN);
            break;
          case 3:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 13, GREEN);
            break;
          case 4:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 12, GREEN);
            break;
          case 5:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 11, GREEN);
            break;
          case 6:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 10, GREEN);
            break;
          case 7:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 9, GREEN);
            break;
          case 8:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 8, GREEN);
            break;
          case 9:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 7, GREEN);
            break;
          case 10:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 6, GREEN);
            break;
          case 11:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 5, GREEN);
            break;
          case 12:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 4, ORANGE);
            matrix.drawLine(2 * j, 15, 2 * j, 5, GREEN);
            break;
          case 13:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 3, ORANGE);
            matrix.drawLine(2 * j, 15, 2 * j, 5, GREEN);
            break;
          case 14:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 2, ORANGE);
            matrix.drawLine(2 * j, 15, 2 * j, 5, GREEN);
            break;
          case 15:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 1, RED);
            matrix.drawLine(2 * j, 15, 2 * j, 2, ORANGE);
            matrix.drawLine(2 * j, 15, 2 * j, 5, GREEN);
            break;
          case 16:
            matrix.drawLine(2 * j, 15, 2 * j, 0, BLACK);
            matrix.drawLine(2 * j, 15, 2 * j, 0, RED);
            matrix.drawLine(2 * j, 15, 2 * j, 2, ORANGE);
            matrix.drawLine(2 * j, 15, 2 * j, 5, GREEN);
            break;
        }
    }
  matrix.swapBuffers(false);   // Update display
}
