/*
 * Lab 4 Kyle Hill.c
 *
 * Created: 10/4/2020 8:00:03 PM
 * Author : kyle0
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#define ON PORTB |= (1<<5)
#define OFF PORTB &= ~(1<<5)


void startTimer()
{
	TCCR0A |= (1<< WGM01);
	OCR0A = 155;				   //I am setting it up so that the each timer counts for 4 ms
	TCCR0B |= (5<<CS00); //Setting prescale for 4ms and starts timer
}


int main(void)
{
	DDRB |= (1<<DDB5); //Set up light
	DDRB &= ~(1<<DDB7); //Set up the push button to be read as an input
	startTimer();
	uint8_t a = 0x7D;
    while (1) 
    {
		if (a == 0) //This is here to prevent OCR0B from hitting 0
			OFF;
		else
		{
			OCR0B = a;
			ON;
			while ( (TIFR0 & (1 << OCF0B) ) == 0){} 
			TIFR0 |= (1 << OCF0B);
		
			OFF;
			while ( (TIFR0 & (1 << OCF0A) ) == 0){} 
			TIFR0 |= (1 << OCF0A);
		}
		if (!(PINB & (1<< 7)))
		{
			if(a != OCR0A)
				a++;
		}
		else if (a!=0)
			a--;
    }
}