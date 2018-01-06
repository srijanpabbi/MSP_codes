#include <msp430.h> 

/*
 * main.c
 */


#define LED BIT0
#define BUTTON BIT3
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR|=LED;
	P1OUT&=~LED;		//TURN OFF THE LED
	P1DIR&=~BUTTON;		//BUTTON INPUT
	P1REN|=BUTTON;		//PULL UP ENABLE
	P1OUT|=BUTTON; //OUTPUT , PULL UP
	while(1)
	{if((P1IN&BUTTON)==0)
	    {
			P1OUT ^= LED;
			__delay_cycles(10000);
			do continue;
			while((P1IN&BUTTON)==0);

		}
	__delay_cycles(10000);
		/*else
			P1OUT&=~LED;*/
	}
	return 0;
}
