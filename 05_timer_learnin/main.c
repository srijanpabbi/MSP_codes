#include <msp430.h> 

/*
 * main.c
 */
int k = 0;
#define LED BIT0
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= LED;
	P1OUT &= ~LED;
	TACCR0 = 10000 - 1;
	TACCTL0 |= CCIE;//this is initialised before because if interrupt is enabled before then we'll loose no counts since timer has not yet started
	TACTL = TACLR + TASSEL_2 + MC_1;		//THIA TO SET THE BASIC MODES
	__enable_interrupt();
	while (1)
		;
	return 0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void CCR0_ISR(void) {
	k++;
	if (k == 100) {	//freq1mhz so timer is 0.01 sec if it counts till 10000-1 so 100 is val if k so 100x0.01 is 1sec
		P1OUT ^= LED;
		k = 0;
	}
}
