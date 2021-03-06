/*
 * Timer0_N_FullLoop.c
 *
 * Created: 3/7/2019 9:00:30 PM
 * Author : VenkatesanMuthukumar
 */ 

#include <avr/io.h>
#define LED 2

int main() {
	uint8_t OVFCount = 0;
	DDRB |= 1 << LED; // configure PORTB.2 as output
	TCNT0 = 0x63;
	// Pre-scalar is 1024
	TCCR0B = (1 << CS02) | (1 << CS00);

	while (1) {
		while ((TIFR0 & 0x01) == 0)
		;
		TCNT0 = 0x63;
		TIFR0 = 0x01; // clear timer1 overflow flag
		OVFCount++;
		if (OVFCount == 10) {
			PORTB ^= (1 << LED);
			OVFCount = 0;
		}
	}
}
