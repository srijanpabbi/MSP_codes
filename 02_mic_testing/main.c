#include <msp430.h> 
/*
 * main.c
 */

#define MicIN1 BIT4
#define MicIN2 BIT5
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR&=~MicIN1;
	P1DIR&=~MicIN2;
	
	return 0;
}
