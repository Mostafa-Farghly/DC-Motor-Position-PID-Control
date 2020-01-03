/*
 * Module: ADC
 * File Name: ADC.h
 * Description: Header file for the MKL25Z4 ADC driver.
 */


#ifndef ADC_H_
#define ADC_H_


#include <MKL25Z4.H>
#include "std_types.h"


/*
 * ADC Input Clock.
 * ADCx_CFG1[ADICLK] value.
 */
typedef enum
{
	Bus_CLK = 0,		/* Bus Clock */
	Bus_CLK_2,			/* Bus Clock divided by 2 */
	ALT_Clk,			/* Alternate Clock */
	Asynch_CLK			/* Asynchronous Clock */
}Input_CLK;


/*
 * CLock Divide Select.
 * ADCx_CFG1[ADIV] value.
 */
typedef enum
{
	Div_1 = 0,			/* Clock division factor = 1 */
	Div_2,				/* Clock division factor = 2 */
	Div_4,				/* Clock division factor = 4 */
	Div_8				/* Clock division factor = 8 */
}CLK_Divide;


/*
 * Select single ended or differential input.
 * ADCx_SC1n[DIFF] value.
 */
typedef enum
{
	Single_Ended = 0,	/* Select Single-ended conversions and input channels */
	Differential,		/* Select Differential conversions and input channels */
}Input_Mode;


/* ADC configurations struct */
typedef struct
{
	Input_CLK CLK;			/* ADC Input Clock. Check enum CLK_Div for available values */
	
	CLK_Divide CLK_Div;		/* Clock Division Factor. Check enum CLK_Divide for available values */
	
	Input_Mode In_Mode;		/* Select single ended or differential input.
								Check enum Input_Mode for available values */
	
	/*TODO*/
	
	uint8 ADC_Pin;			/* Pin number connected to ADC */
	
	/*
	 * Port: Pointer of type PORT_Type defined in "MKL25Z4.H" header file
	 * Choose a Port to connect to ADC
	 * Assigned values should be one of 
	 * (PORTB, PORTC, PORTD, or PORTE); defined in "MKL25Z4.H" header file
	 */
	PORT_Type *Port;
	
}ADC_ConfigType;


/*
 * Name: ADC_init
 * Description: Initialize the ADC driver.
 * @Return: void
 * @Param: Pointer to a struct ADC_ConfigType
 */
void ADC_init(const ADC_ConfigType *Config_ptr);


#endif /* ADC_H_ */




