/*
 * Module: ADC
 * File Name: ADC.c
 * Description: Source file for the MKL25Z4 ADC driver.
 */


#include "ADC.h"


/* ADC Initialization function */
void ADC_init(const ADC_ConfigType *Config_ptr)
{
	/* Gate clock to the ADC Module */
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	/* Configure choosen port pin */
	/* Gate clock to the choosen port pin */
	/*TODO*/
	/* Select analog for pin */
	Config_ptr->Port->PCR[Config_ptr->ADC_Pin] &= ~PORT_PCR_MUX_MASK;
	Config_ptr->Port->PCR[Config_ptr->ADC_Pin] |= PORT_PCR_MUX(0);
	
	/*TODO*/
}
