/*
 * File        : main.c
 * Description : This file includes ADC test applications for Atmega32
 *               the application reads 2 analog value throght 2 ADC channels and display them on LCD
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */ 

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "LDELAY_Interface.h"
#include "MDIO_Interface.h"
#include "MADC_Interface.h"
#include "HLCD_Interface.h"


int main(void)
{
	/************************************************************************
	 * Global variables                                                   
	 ************************************************************************/
	/*ADC channel 1 analog value*/
	volatile u32 ADC_AnalogValue1 = 0;
	/*ADC channel 2 analog value*/
	volatile u32 ADC_AnalogValue2 = 0;
    
	/************************************************************************
	 * Program initializations                                                   
	 ************************************************************************/
	 /*Initialize ADC Channel pins as input*/
	 MDIO_u8SetDirectionBit(MDIO_PORTA,MDIO_PA0,MDIO_INPUT);
	 MDIO_u8SetDirectionBit(MDIO_PORTA,MDIO_PA1,MDIO_INPUT);
	 /*initialize ADC*/
	 MADC_voidInitializeADC();
	 /*initialize LCD with cursor off*/
	 HLCD_voidInitializeLCD();
	 HLCD_voidCursorDisplayOnOff(HLCD_OFF);
     HLCD_voidCursorBlinkOnOff(HLCD_OFF);
	 
	 /*Display fixed strings*/
     HLCD_voidDisplayString("ADC0:",HLCD_STRING);
	 HLCD_voidSetCursorPosition(HLCD_LINE2,1);
	 HLCD_voidDisplayString("ADC1:",HLCD_STRING);
	
	 while (1) 
     {
		 /*Update analog value at ADC Channel 1*/
		 ADC_AnalogValue1 = MADC_u32GetAnalogValueSynch(MADC_ADC0);
		 /*erase past value*/
		 HLCD_voidSetCursorPosition(HLCD_LINE1,7);
		 HLCD_voidDisplayString("          ",HLCD_STRING);
		 /*Display new value*/
		 HLCD_voidSetCursorPosition(HLCD_LINE1,7);
		 HLCD_voidDisplayString(&ADC_AnalogValue1,HLCD_NUMBER);
		 /*write mv next to analog value*/
		 HLCD_voidSetCursorPosition(HLCD_LINE1,12);
		 HLCD_voidDisplayString("mv",HLCD_STRING);
		 /*wait 5 milliseconds*/
		 LDelay_voidDelay_ms(1);
		 
		 /*Update analog value at ADC Channel 1*/
		 ADC_AnalogValue2 = MADC_u32GetAnalogValueSynch(MADC_ADC1);
		 /*erase past value*/
		 HLCD_voidSetCursorPosition(HLCD_LINE2,7);
		 HLCD_voidDisplayString("          ",HLCD_STRING);
		 /*Display new value*/
		 HLCD_voidSetCursorPosition(HLCD_LINE2,7);
		 HLCD_voidDisplayString(&ADC_AnalogValue2,HLCD_NUMBER);
		 /*write mv next to analog value*/
		 HLCD_voidSetCursorPosition(HLCD_LINE2,12);
		 HLCD_voidDisplayString("mv",HLCD_STRING);
		 /*wait 5 milliseconds*/
		 LDelay_voidDelay_ms(1);
		
     }/*end of infinite loop*/

}/*end of main()*/

