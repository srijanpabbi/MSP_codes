#include <msp430.h> 

/*
 * main.c
 */

#define LED1 BIT0
#define SWC BIT3
void clockChange(int flag){
	switch(flag){
	case 0 :{
		BCSCTL1&=~(BIT3+BIT2);		//CAN BE WRITTEN AS &=RSEL1 AMD SO ON IN FURTHER CLEARINGS
		BCSCTL1|=(BIT0+BIT1);
		DCOCTL&=~BIT7;
		DCOCTL|=(BIT5+BIT6);
		break;
	}
	case 1 :{
		BCSCTL1&=~(BIT0+BIT1+BIT2);
		BCSCTL1|=BIT3;
		DCOCTL&=~BIT7;
		DCOCTL|=(BIT5+BIT6);
		break;

	}
	}
}
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR|=LED1;
	P1OUT&=~LED1;
	P1DIR&=~SWC;
	P1REN|=SWC;	//PULLUP/PULLDOWN ENABLE
	P1OUT|=SWC; 	//PULLUP
	int flag=0;
	clockChange(flag);		// is called here to make the clock freq 0.3MHz initially
	while(1){
		if(P1IN&SWC){
			P1OUT^=LED1;
			__delay_cycles(70000);
		}
		else{
			__delay_cycles(20000);
			while((P1IN&SWC)==0);		//never write !(---) cause if we get 0x00 so !(0x00) is 11 which is not equal to 1 ie 00000001
			__delay_cycles(20000);
			if(P1IN&SWC){
				flag++;
				if(flag==2)flag=0;
				clockChange(flag);
			}
		}
	}
	return 0;
}
