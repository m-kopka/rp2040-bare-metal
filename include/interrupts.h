#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#define ISR_WEAK __attribute__ ((weak, alias("Default_Handler")))

//---- ARM Cortex M0+ exeptions -----------------------------------------------------------------------------------------------------------------------------------

void          Reset_Handler();          // Reset Handler
void ISR_WEAK NMI_Handler();            // Non maskable interrupt
void ISR_WEAK HardFault_Handler();      // All class of fault
void ISR_WEAK SVCall_Handler();         // System Service call via SWI instruction
void ISR_WEAK PendSV_Handler();         // Pendable request for system service
void ISR_WEAK Systick_Handler();        // System tick timer

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void ISR_WEAK Timer0_Handler();         // Timer alarm 0
void ISR_WEAK Timer1_Handler();         // Timer alarm 1
void ISR_WEAK Timer2_Handler();         // Timer alarm 2
void ISR_WEAK Timer3_Handler();         // Timer alarm 3
void ISR_WEAK PWM_Handler();            // PWM interrupt
void ISR_WEAK USB_CTRL_Handler();       // USB interrupt
void ISR_WEAK XIP_Handler();            // XIP interrupt
void ISR_WEAK PIO0_0_Handler();         // PIO0 interrupt 0
void ISR_WEAK PIO0_1_Handler();         // PIO0 interrupt 1
void ISR_WEAK PIO1_0_Handler();         // PIO1 interrupt 0
void ISR_WEAK PIO1_1_Handler();         // PIO1 interrupt 1
void ISR_WEAK DMA0_Handler();           // DMA0 interrupt
void ISR_WEAK DMA1_Handler();           // DMA1 interrupt
void ISR_WEAK IO_Bank0_Handler();       // IO_BANK0 interrupt
void ISR_WEAK IO_QSPI_Handler();        // IO_QSPI interrupt
void ISR_WEAK SIO_Proc0_Handler();      // SIO_PROC0 interrupt
void ISR_WEAK SIO_Proc1_Handler();      // SIO_PROC1 interrupt
void ISR_WEAK Clocks_Handler();         // CLOCK interrupt
void ISR_WEAK SPI0_Handler();           // SPI0 interrupt
void ISR_WEAK SPI1_Handler();           // SPI1 interrupt
void ISR_WEAK UART0_Handler();          // UART0 interrupt
void ISR_WEAK UART1_Handler();          // UART1 interrupt
void ISR_WEAK ADC_FIFO_Handler();       // ADC_FIFO interrupt
void ISR_WEAK I2C0_Handler();           // I2C0 interrupt
void ISR_WEAK I2C1_Handler();           // I2C1 interrupt
void ISR_WEAK RTC_Handler();            // RTC interrupt

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

// empty handler for unhandled exeptions
void Default_Handler();

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif /* _INTERRUPTS_H_ */