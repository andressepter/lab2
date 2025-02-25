#include <stdbool.h>
#include <stdint.h>

#include "common/bump.h"
#include "common/delay.h"
#include "common/clock.h"
#include "inc/msp432p401r.h"

#define DEBUG_SIZE 256
volatile uint8_t bumpDataArray[DEBUG_SIZE];
volatile uint8_t lineDataArray[DEBUG_SIZE];
volatile uint8_t debugIndex = 0;

volatile uint8_t bumpData = 0;

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 3000; i++) {
        __NOP();
    }
}

void DebugDump(uint8_t bumpData, uint8_t lineData) {
    bumpDataArray[debugIndex] = bumpData;
    lineDataArray[debugIndex] = lineData;
    debugIndex = (debugIndex + 1) % DEBUG_SIZE;
}



int main(void) {
    // write this as part of Lab 2
    
    ClockInit48MHz();
    BumpInit();

    while (true) {
        bumpData = BumpRead();
        uint8_t lineData = 0; 
        DebugDump(bumpData, lineData);
        delay_ms(10);
        
    }
}
