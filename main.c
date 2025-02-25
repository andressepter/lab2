#include <stdbool.h>
#include <stdint.h>

#include "common/bump.h"
#include "common/delay.h"
#include "common/clock.h"
#include "inc/msp432p401r.h"

void DebugDump(uint8_t bump) {
    // write this as part of Lab 2
}

int main(void) {
    // write this as part of Lab 2
    
    ClockInit48MHz();

    while (true) {
        WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // Stop watchdog timer
        // write this as part of Lab 2
        // 10ms delay
        // debug dump
    }
}
