/*
 * Lab 2 Kyle Hill.c
 *
 * Created: 9/17/2020 12:41:53 PM
 * Author : kyle0
 */ 
#define F_CPU 16000000UL  // 16MHz clock from the debug processor
#include <avr/io.h>
#include <util/delay.h>


// function to initialize UART
void USART_Init(void)
{
	UBRR0H = 0;
	UBRR0L = 103;
	UCSR0B |= (1<<RXEN0);          //Enable Receiver
	UCSR0B |= (1<<TXEN0);          //Enable Transmitter
	UCSR0C &= ~(0<<USBS0);      //Set to  1-stop bit
	UCSR0C |= (3<<UCSZ00);       //Set to 8 data bits
}

void uart_transmit (unsigned char data[], int n) {
	while (!( UCSR0A & (1<<UDRE0))); // wait while register is free
	UDR0 = data[n]; // load data in the register
}

int main(void)
{
	unsigned char data[] = "822376692 ";
	int n;
	DDRD |= (1<<DDD1);
	USART_Init();
	while(1)
	{
		for (n=0; n<=9; n++){
			uart_transmit(data, n);
		}
		_delay_ms(500);
	}
}