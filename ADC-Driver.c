/*
 * ADC_Driver.c
 *
 * Created: 3/8/2018 2:19:53 PM
 *  Author: mahmoud
 */ 
#include "ADC-Driver.h"

#include <avr/io.h>
#include <avr/interrupt.h>


void Adc_Initialization(void)
{
	DDRA &=~((1U<<ADC0)|(1U<<ADC1)|(1U<<ADC2));								//make PORTA direction as input
	
	
	ADCSRA |=(1U<<ADPS0);													//select conversion time  ck/64 (8M/64) = 125 k
	ADCSRA |=(1U<<ADPS1);													//select conversion time  ck/64 (8M/64) = 125 k
	ADCSRA |=(1U<<ADPS2);													//select conversion time  ck/64 (8M/64) = 125 k
	
	ADMUX |=(1U<<REFS0);													//reference voltage same as VCC (AVCC)
	ADMUX &=~(1U<<REFS1);													//reference voltage same as VCC (AVCC)

	ADMUX &=~((1U<<MUX0)|(1U<<MUX1)|(1U<<MUX2)|(1U<<MUX3)|(1U<<MUX4));		//channel 0 (ADC0)
	
	ADMUX &=~(1U<<ADLAR);													//right adjustment
	
	ADCSRA |=(1U<<ADIE);													//enable ADC interrupt
	
	sei();																	//enable global interrupts
	
	ADCSRA |=(1U<<ADEN);													// enable ADC module
	
	ADCSRA |=(1U<<ADSC);													//start conversion
}

uint16_t Adc_OutputValue(void)
{
	while (ADCSRA&(1U<<ADIF)== 0);
	uint16_t adc_reading=0;
	adc_reading = ADCL |(ADCH<<8);		//read the ADC value
	return adc_reading;
}
