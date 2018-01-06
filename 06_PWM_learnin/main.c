
#include <msp430.h> 

/*
 * main.c
 */
/*
 * description:
 * the program demonstrates the generation of PWM using timer of msp430g2553.
 * the frequency (or the time peiod) is defined by the taccr0.  the up time of the pwm is defined by taccr1.
 * the timer is operated in the output mode 7whic is set reset
 */
#define LED BIT1
int main(void) {
   WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR|=LED;		//LED AS OUTPUT
	P1OUT&=~LED;		//SWITCHING LED AS OFF
	/*P1SEL|=LED;		//SELECTING PORT FUNCTIONS TO TA0 FROM THE CHAPTER PORT SCHEMATICS IE. TIMER 0 PRIMARY FUNCTION
	TACCR0=400-1;		//SETTING FREQUENCY OF THE PWM
	TACCR1=200-1;		//SETTNG THE DUTY CYCLE
	TACTL=TACLR+TASSEL_2+MC_1;		//SETTING THE CLOCK SMCLK, TIMER IN UP MODE
	TACCTL1=OUTMOD_7;		//SETTING OUTPUT MODE TO 7 IE. SET/RESET*/
	while(1){
		P1OUT|=LED;
		P1OUT&=~LED;
	}
	return 0;
}
