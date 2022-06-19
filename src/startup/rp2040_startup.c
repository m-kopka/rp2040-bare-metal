
#include <stdint.h>
#include "startup/memory_config.h"
#include "startup/vector_table.h"

extern int main() __attribute__ ((section (".text")));

// entry point
void Reset_Handler() {

    // copy .data segment from FLASH to SRAM
    uint32_t *p_src = (uint32_t*)&_la_data;
    uint32_t *p_dst = (uint32_t*)&_sdata;

    for (uint32_t i = 0; i < DATA_SIZE; i++) {

        *p_dst++ = *p_src++;
    }

    // initialize .bss segment to 0
    p_dst = (uint32_t*)&_sbss;

    for (uint32_t i = 0; i < BSS_SIZE; i++) {

        *p_dst++ = 0x00000000;
    }

    main();     // branch to main
}

void Default_Handler() {

    return;
}
