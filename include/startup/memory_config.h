#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

#define SRAM_START  0x20000000U                     // SRAM start address
#define SRAM_SIZE   (264U * 1024U)                  // SRAM size (264K)
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))    // SRAM end address

#define STACK_TOP   SRAM_END            // stack init value

extern uint32_t _la_data;       // start address of .data segment in FLASH
extern uint32_t _sdata;         // start address of .data segment in SRAM
extern uint32_t _edata;         //   end address of .data segment in SRAM
extern uint32_t _sbss;          // start address of .bss segment in SRAM 
extern uint32_t _ebss;          //   end address of .bss segment in SRAM

#define DATA_SIZE (((uint32_t)&_edata) - ((uint32_t)&_sdata))       // .data segment size
#define BSS_SIZE  (((uint32_t)&_ebss) - ((uint32_t)&_sbss))         // .bss segment size

#endif /* _VECTOR_TABLE_H_ */