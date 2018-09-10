/*
 * ADC_Driver.h
 *
 * Created: 3/8/2018 5:11:00 PM
 *  Author: mahmoud
 */ 


#ifndef ADC-DRIVER_H_
#define ADC-DRIVER_H_

#include <stdint.h>
#define ADC0 (0)
#define ADC1 (1)
#define ADC2 (2)

void Adc_Initialization(void);

uint16_t Adc_OutputValue(void);

#endif /* ADC-DRIVER_H_ */

