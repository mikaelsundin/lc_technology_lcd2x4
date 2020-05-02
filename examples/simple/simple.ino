/** 
 * Simple example for, print 0 to 8 on display
 */

#define data_pin  2
#define clk_pin   3

#include <led2x4.h>
Led2x4 led;

void setup() {
  led.begin(data_pin,clk_pin); //Pin 2 data, Pin 3 clock

  led.write(0,0);
  led.write(1,1);
  led.write(2,2);
  led.write(3,3);
  led.write(4,4);
  led.write(5,5);
  led.write(6,6);
  led.write(7,7);

}


void loop() {
  led.refresh();
  delayMicroseconds(1500);

}
