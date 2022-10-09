/*
 * Lab 6 Kyle Hill.c
 *
 * Created: 10/27/2020 1:31:46 PM
 * Author : kyle0
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#define ON PORTB |= (1<<5)
#define OFF PORTB &= ~(1<<5)
#define row 4
#define col 4

//These last 2 defines aren't used just here for clarification on why I have 7ms delay and 300Hz
#define x   6
#define z   2

//All function prototypes
void startTimer0(void);
void startTimer2(void);
void setPins(void);
void scanpad(void);
void setFreq(int r, int c);
void setInterrupts(void);

uint8_t f[row][col] = {
	{19,  40,  61,  0},
	{82,  103, 123, 0},
	{144, 165, 186, 0},
	{0,   0,   0,   0}
};

int main(void)
{
	setPins();
	setInterrupts();
	startTimer0();
	
	while (1)
	{
		//scanpad();
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

//This set all the pins so that they can be properly manipulated
void setPins()
{
	DDRB |= (1<<DDB5); //Set up light
	DDRB &= 0xF0; //Sets up Pins B 0-3 to be Inputs
	PORTB |= 0x0F; //Sets pull-up resistors so that pressing the button will make it low
	DDRD |= 0xF0; // Sets Pins D 4-7 to be Output
}

void scanpad()
{
	int r, c;
	for(r = 0; r <row; r++)
	{
		PORTD|= 0xF0;
		PORTD &= ~(1<< (r+4));
		for(c = 0; c <col; c++)
		{
			if (!(PINB & (1 << c)))
			{
				setFreq(r,c);
			}
		}
	}
}

//This controls the frequency of the LED based on which buttons is pressed also calls the start timer 2 function
void setFreq(int r, int c)
{
	startTimer2();
	//Does nothing when pressing none number button
	if ((c==3)||(r==3))
	{
		//Has special case when 0 pressed because I have had issues with duty cycle 0
		if (c==1)
		{
			// This stops the timer 2 when pressing 0 so that the LED will stay off
			TCCR2B &= ~(3<<CS21);
			OFF;
		}
	}
	else
	{
		OCR2B = f[r][c];
	}
}

//This set up all the interrupts that will be used
void setInterrupts()
{
	TIMSK0 |= (1<<OCIE0A);
	TIMSK2 |= (3<<OCIE2A);
	sei();
}

//This calls the scanpad function whenever 7ms passes

ISR (TIMER0_COMPA_vect)
{
	scanpad();
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