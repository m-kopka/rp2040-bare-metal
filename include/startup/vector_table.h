#ifndef _VECTOR_TABLE_H_
#define _VECTOR_TABLE_H_

#include <stdint.h>
#include "startup/memory_config.h"
#include "interrupts.h"

uint32_t *vector_table[] __attribute__((section(".vector_table"))) = {

    (uint32_t*)STACK_TOP,                   // stack init value
    (uint32_t*)Reset_Handler,               // Reset vector
    (uint32_t*)NMI_Handler,                 // Non maskable interrupt
    (uint32_t*)HardFault_Handler,           // All class of fault
    0,                                      // (reserved)
    0,                                      // (reserved)
    0,                                      // (reserved)
    0,                                      // (reserved)
    0,                                      // (reserved)
    0,                                      // (reserved)
    0,                                      // (reserved)
    (uint32_t*)SVCall_Handler,              // System Service call via SWI instruction
    0,                                      // (reserved)
    0,                                      // (reserved)
    (uint32_t*)PendSV_Handler,              // Pendable request for system service
    (uint32_t*)Systick_Handler,             // System tick timer
    (uint32_t*)Timer0_Handler,              // Timer alarm 0
    (uint32_t*)Timer1_Handler,              // Timer alarm 1
    (uint32_t*)Timer2_Handler,              // Timer alarm 2
    (uint32_t*)Timer3_Handler,              // Timer alarm 3
    (uint32_t*)PWM_Handler,                 // PWM interrupt
    (uint32_t*)USB_CTRL_Handler,            // USB interrupt
    (uint32_t*)XIP_Handler,                 // XIP interrupt
    (uint32_t*)PIO0_0_Handler,              // PIO0 interrupt 0
    (uint32_t*)PIO0_1_Handler,              // PIO0 interrupt 1
    (uint32_t*)PIO1_0_Handler,              // PIO1 interrupt 0
    (uint32_t*)PIO1_1_Handler,              // PIO1 interrupt 1
    (uint32_t*)DMA0_Handler,                // DMA0 interrupt
    (uint32_t*)DMA1_Handler,                // DMA1 interrupt
    (uint32_t*)IO_Bank0_Handler,            // IO_BANK0 interrupt
    (uint32_t*)IO_QSPI_Handler,             // IO_QSPI interrupt
    (uint32_t*)SIO_Proc0_Handler,           // SIO_PROC0 interrupt
    (uint32_t*)SIO_Proc1_Handler,           // SIO_PROC1 interrupt
    (uint32_t*)Clocks_Handler,              // CLOCK interrupt
    (uint32_t*)SPI0_Handler,                // SPI0 interrupt
    (uint32_t*)SPI1_Handler,                // SPI1 interrupt
    (uint32_t*)UART0_Handler,               // UART0 interrupt
    (uint32_t*)UART1_Handler,               // UART1 interrupt
    (uint32_t*)ADC_FIFO_Handler,            // ADC_FIFO interrupt
    (uint32_t*)I2C0_Handler,                // I2C0 interrupt
    (uint32_t*)I2C1_Handler,                // I2C1 interrupt
    (uint32_t*)RTC_Handler,                 // RTC interrupt
};

#endif /* _VECTOR_TABLE_H_ */