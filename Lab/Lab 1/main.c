/*
 * Lab 1 Kyle Hill.c
 *
 * Created: 9/10/2020 10:14:16 AM
 * Author : kyle0
 */ 

#define F_CPU 16000000UL  // 16MHz clock from the debug processor
#include <avr/io.h>
#include <util/delay.h>

void dot(void)
{
	PORTB |= (1<<PORTB5); //Set port bit B5 to 1 to turn on the LED
	_delay_ms(200);  
	PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200); // I add the delay at the end of dots and dashes so I don't have to do dash space dot space space space... this makes it easier
					// and also allows for the space between words and letters to be divisible by 400ms (400ms for space between letters and 1200ms for space between words)
}
void dash(void)
{
	PORTB |= (1<<PORTB5); 
	_delay_ms(600);  
	PORTB &= ~(1<<PORTB5); 
	_delay_ms(200);
}
void space(void)
{
	_delay_ms(400);
}
	
	
int main(void)
{
	char str[] = "Kyle Hill 822376692";
	int n = 0; //n will be used to go through the array char by char
	DDRB |= (1<<DDB5);  //0x20 (hex) // Set port bit B5 in data direction register to 1: an OUTput
	while(1){
		if (str[n] == 'a' || str[n] == 'A')
		{
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'b' || str[n] == 'B')
		{
			dash();
			dot();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'c' || str[n] == 'C')
		{
			dash();
			dot();
			dash();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'd' || str[n] == 'D')
		{
			dash();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'e' || str[n] == 'E')
		{
			dot();
			space();
			n++;
		}
		else if (str[n] == 'f' || str[n] == 'F')
		{
			dot();
			dot();
			dash();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'g' || str[n] == 'G')
		{
			dash();
			dash();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'h' || str[n] == 'H')
		{
			dot();
			dot();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'i' || str[n] == 'I')
		{
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'j' || str[n] == 'J')
		{
			dot();
			dash();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'k' || str[n] == 'K')
		{
			dash();
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'l' || str[n] == 'L')
		{
			dot();
			dash();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'm' || str[n] == 'M')
		{
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'n' || str[n] == 'N')
		{
			dash();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'o' || str[n] == 'O')
		{
			dash();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'p' || str[n] == 'P')
		{
			dot();
			dash();
			dash();
			dot();
			space();
			n++;
		}
		else if (str[n] == 'q' || str[n] == 'Q')
		{
			dash();
			dash();
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'r' || str[n] == 'R')
		{
			dot();
			dash();
			dot();
			space();
			n++;
		}
		else if (str[n] == 's' || str[n] == 'S')
		{
			dot();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == 't' || str[n] == 'T')
		{
			dash();
			space();
			n++;
		}
		else if (str[n] == 'u' || str[n] == 'U')
		{
			dot();
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'v' || str[n] == 'V')
		{
			dot();
			dot();
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'w' || str[n] == 'W')
		{
			dot();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'x' || str[n] == 'X')
		{
			dash();
			dot();
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'y' || str[n] == 'Y')
		{
			dash();
			dot();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == 'z' || str[n] == 'Z')
		{
			dash();
			dash();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == ' ')
		{
			space();
			space();
			space();
			n++;
		}
		else if (str[n] == '0')
		{
			dash();
			dash();
			dash();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == '1')
		{
			dot();
			dash();
			dash();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == '2')
		{
			dot();
			dot();
			dash();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == '3')
		{
			dot();
			dot();
			dot();
			dash();
			dash();
			space();
			n++;
		}
		else if (str[n] == '4')
		{
			dot();
			dot();
			dot();
			dot();
			dash();
			space();
			n++;
		}
		else if (str[n] == '5')
		{
			dot();
			dot();
			dot();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == '6')
		{
			dash();
			dot();
			dot();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == '7')
		{
			dash();
			dash();
			dot();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == '8')
		{
			dash();
			dash();
			dash();
			dot();
			dot();
			space();
			n++;
		}
		else if (str[n] == '9')
		{
			dash();
			dash();
			dash();
			dash();
			dot();
			space();
			n++;
		}
		else // At this point the only char left to account for is the null char which means I would be at the end and have to reset to the beginning
		{
			space();
			space();
			space();
			n = 0;
		}
	}
}

