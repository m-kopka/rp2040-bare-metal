
#include <stdint.h>

#define _SFR(address) (*(volatile uint32_t*)((address)))

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

#define RESETS_BASE			0x4000c000 					// Reset controller registers base

#define RESETS_RESET		_SFR(RESETS_BASE + 0x00)   	// RESET register
#define RESETS_RESET_DONE	_SFR(RESETS_BASE + 0x08)	// RESET_DONE Register

#define RESETS_IO_BANK0		(1 << 5)					// RESET IO_BANK0

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

#define IO_BANK0_BASE 			0x40014000						// User Bank IO registers

#define IO_BANK0_GPIO25_CTRL 	_SFR(IO_BANK0_BASE + 0x0cc)		// GPIO25 control including function select and overrides

#define GPIO_FUNC_SIO	5										// Software control of GPIO

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

#define SIO_BASE 			0xd0000000 					// Single-cycle block registers base

#define SIO_GPIO_OE_SET		_SFR(SIO_BASE + 0x024)		// GPIO25 output enable SET register
#define SIO_GPIO_OUT_XOR	_SFR(SIO_BASE + 0x01c) 		// GPIO25 output value XOR register

#define GPIO25				 (1 << 25)

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {

	RESETS_RESET &= ~RESETS_IO_BANK0; 						// clear RESETS_IO_BANK bit
	while (!(RESETS_RESET_DONE & RESETS_IO_BANK0)); 		// wait for RESET_DONE flag to set

	IO_BANK0_GPIO25_CTRL = GPIO_FUNC_SIO; 	// set GPIO25 function to SIO
	SIO_GPIO_OE_SET = GPIO25;				// set GPIO25 output enable

	while (1) {

		SIO_GPIO_OUT_XOR = GPIO25; 											// flip LED pin
		for (volatile unsigned int i = 0; i < 400000; i++) asm("nop");		// busy wait
	}
}
