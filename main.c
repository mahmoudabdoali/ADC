/*
 * ADC.c
 *
 * Created: 9/10/2018 5:21:04 PM
 * Author : Mahmoud
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ADC-Driver.h"


int main(void)
{
	Adc_Initialization();
	uint16_t readed_data=0;
	
	
    while (1) 
    {
		readed_data=Adc_OutputValue();	
    }
}

