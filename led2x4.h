#ifndef _LED2X4_H_
#define _LED2X4_H_

#include <stdint.h>

class Led2x4
{
    public:
        Led2x4(void);
        
        void begin(int dataPin, int clockPin);
        void refresh(void);
        
        void write(uint8_t digit, uint8_t value);
        
        
    private:
        int _clk;
        int _data;
        uint8_t _index;
        uint8_t _out[8];  
};

#endif

