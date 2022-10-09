/*
 * Lab 7 Kyle Hill.c
 *
 * Created: 11/8/2020 8:55:49 PM
 * Author : kyle0
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#define ON PORTB |= (1<<5)
#define OFF PORTB &= ~(1<<5)

#define x 6
#define y 9
#define z 2

//All unction prototypes
void startTimer0(void);
void startTimer2(void);
void startADC(void);
void setPins(void);
void setInterrupts(void);


int main(void)
{
	setPins();
	setInterrupts();
	
    startTimer0();

    while (1) 
    {
    }
}


void startTimer0()
{
	//Set Timer 0 for CTC mode
	TCCR0A |= (1<<WGM01);
	//Set OCR0A and prescale so that the timer delays by 7ms
	OCR0A = 108;
	TCCR0B|= (5 << CS00);
}

void startTimer2()
{
	//Sets Timer 2 for CTC mode
	TCCR2A |= (1<<WGM21);
	//Prescale and OCR2A set up so that frequency is 300Hz = (z + 1)*100
	OCR2A = 207;
	TCCR2B |= (3<<CS21);
}

void startADC()
{
	DDRC &= ~(1<< DDC3); //Set up input
	
	ADMUX   = (1<<REFS0);
	ADMUX  |= (3<<MUX0);  //Channel 3 = 9 % 6
	ADMUX  |= (1<<ADLAR);  //Left shift bits so I read directly from the High register
	
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (7<<ADPS0);  //Prescale 128
	ADCSRA |= (1<<ADSC);   //Start conversion
}

//This set all the pins so that they can be properly manipulated
void setPins()
{
	DDRB |=  (1<<DDB5);  //Set up light
}

//This set up all the interrupts that will be used
void setInterrupts()
{
	TIMSK0 |= (1<<OCIE0A);
	TIMSK2 |= (3<<OCIE2A);
	ADCSRA |= (1<<ADIE);
	sei();
}

ISR (TIMER0_COMPA_vect)
{
	startADC();
}

//This calls the  function whenever ADC finishes
ISR (ADC_vect)
{
	startTimer2();
	if (ADCH == 0)
	{
		TCCR2B &= ~(3<<CS21);
		OFF;
	}
	else
	{
		OCR2B = OCR2A*ADCH/255;
	}
	PINC ^= (1<<3);
}

//This turns on LED when Timer 2 reaches OCR2A
ISR (TIMER2_COMPA_vect)
{
	ON;
}

//This turns off LED when Timer 2 reaches OCR2B
ISR (TIMER2_COMPB_vect)
{
	OFF;
}
