#include <arduino.h>
#include "led2x4.h"

Led2x4::Led2x4(void){
    //all off
    memset(_out, 0xFF, 8);
}

void Led2x4::begin(int dataPin, int clockPin){
    _data = dataPin;
    _clk = clockPin;
    
    pinMode(_clk, OUTPUT);
    pinMode(_data , OUTPUT);
}

/**
 * Call often to refresh next digit 
 */
void Led2x4::refresh(void){
    uint8_t index = (_index++) % 0x08;
    
    shiftOut(_data, _clk, MSBFIRST, _out[index]); //Segments cathode
    shiftOut(_data, _clk, MSBFIRST, 1<<index);        //Common anode

}

void Led2x4::write(uint8_t digit, uint8_t value, bool dot=false){
  uint8_t lookup[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
  uint8_t tmp;

  //only 8 digits exist on LED
  if(digit >= 8){
    return;
  }

  //only 0-9 is supported
  if(value > 9){
    return;
  }
  
  // tmp = lookup[digit]; -> ther was an error :(
  tmp = lookup[value];
  tmp |= dot ? 0x80 : 0x00; // add 0x80 if dot shall be lit
  
  _out[digit] = ~tmp;
}
