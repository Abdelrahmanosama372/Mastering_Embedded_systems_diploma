/*
 * stm32f103x6_EXTI_driver.c
 *
 *
 *      Author: Abdelrahman osama
 */

#include "stm32f103x6_EXTI_driver.h"



void Enable_NVIC(uint8_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_ENABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE;
		break;
	}
}

void Disable_NVIC(uint8_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE;
		break;
	}
}
/*
 *====================================================================
 *						  Generic Variables
 *====================================================================
 */

 void (*GP_IRQ_Callback_FUNS[15])(void);
/*
 *====================================================================
 *						  Generic Macros
 *====================================================================
 */
#define AFIO_EXTI_GPIO_mapping(GPIO) ((GPIO == GPIOA)? 0:\
						(GPIO == GPIOB)? 1:\
						(GPIO == GPIOC)? 2:\
						(GPIO == GPIOD)? 3:0)


/*
 *====================================================================
 *						  Generic Functions
 *====================================================================
 */
void GPIO_Update(EXTI_pinConfig_t *EXTI_pin)
{
	// configure pin as floating input
	GPIO_Pin_Config config_pin;
	config_pin.Pin_Mode = Floating_Input;
	config_pin.Pin_Number = EXTI_pin->EXTI_GPIO_pin.Pin_number;
	MCAL_GPIO_Init(EXTI_pin->EXTI_GPIO_pin.port , &config_pin);
	//===============================================================

	// enable AFIO to rout the EXTI
	uint8_t AFIO_EXTICR_index = EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_pos = (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber % 4) *4;
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_pos);
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_EXTI_GPIO_mapping(EXTI_pin->EXTI_GPIO_pin.port)) << AFIO_EXTICR_pos) ;
	//================================================================


	//update trigger case Rising or Falling or both
	EXTI->RTSR &= ~(1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
	EXTI->FTSR &= ~(1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));

	if (EXTI_pin->trigger_case == EXTI_RISING_Trigger)
	{
		EXTI->RTSR |= (1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
	}
	else if(EXTI_pin->trigger_case == EXTI_FALLING_Trigger)
	{
		EXTI->FTSR |= (1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
	}
	else if(EXTI_pin->trigger_case == EXTI_RisingAndFalling_trigger)
	{
		EXTI->RTSR |= (1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
		EXTI->FTSR |= (1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
	}
	//==================================================================

	// update the IRQ call_back function
	GP_IRQ_Callback_FUNS[EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber] = EXTI_pin->P_IRQ_callback;
	//==================================================================

	// enable/disable IRQ EXTI & NVIC
	if(EXTI_pin->IR_EN == EXTI_IRQ_ENABLE)
	{
		EXTI->IMR |= (1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
		Enable_NVIC(EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber);
	}else
	{
		EXTI->IMR &= ~(1 << (EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber));
		Disable_NVIC(EXTI_pin->EXTI_GPIO_pin.EXTI_InputLineNumber);
	}

}
/*
 *====================================================================
 *					APIs Functions Declaration
 *====================================================================
 */

void MCAL_EXTI_GPIO_Init(EXTI_pinConfig_t *EXTI_pin)
{
	GPIO_Update(EXTI_pin);
}

void MCAL_EXTI_GPIO_Update(EXTI_pinConfig_t *EXTI_pin)
{
	GPIO_Update(EXTI_pin);
}
void MCAL_EXTI_GPIO_DeInit()
{
// reset EXTI peripheral
	EXTI->IMR   =  0x00000000;
	EXTI->EMR   =  0x00000000;
	EXTI->RTSR  =  0x00000000;
	EXTI->FTSR  =  0x00000000;
	EXTI->SWIER =  0x00000000;
	EXTI->PR    =  0xFFFFFFFF;
// Disable NVIC IRQ
	NVIC_IRQ6_EXTI0_DISABLE;
    NVIC_IRQ7_EXTI1_DISABLE;
	NVIC_IRQ8_EXTI2_DISABLE;
	NVIC_IRQ9_EXTI3_DISABLE;
	NVIC_IRQ10_EXTI4_DISABLE;
	NVIC_IRQ23_EXTI5_9_DISABLE;
	NVIC_IRQ40_EXTI10_15_DISABLE;
}

void EXTI0_IRQHandler(void)
{
	//clear IRQ by writing 1 into pending registers EXTI_PR
	EXTI->PR |= (1 << 0);
	// call the IRQ callback function
	GP_IRQ_Callback_FUNS[0]();

}
void EXTI1_IRQHandler(void)
{
	//clear IRQ by writing 1 into pending registers EXTI_PR
	EXTI->PR |= (1 << 1);
	// call the IRQ callback function
	GP_IRQ_Callback_FUNS[1]();
}


void EXTI2_IRQHandler(void)
{
	//clear IRQ by writing 1 into pending registers EXTI_PR
	EXTI->PR |= (1 << 2);
	// call the IRQ callback function
	GP_IRQ_Callback_FUNS[2]();
}


void EXTI3_IRQHandler(void)
{
	//clear IRQ by writing 1 into pending registers EXTI_PR
	EXTI->PR |= (1 << 3);
	// call the IRQ callback function
	GP_IRQ_Callback_FUNS[3]();
}


void EXTI4_IRQHandler(void)
{
	//clear IRQ by writing 1 into pending registers EXTI_PR
	EXTI->PR |= (1 << 4);
	// call the IRQ callback function
	GP_IRQ_Callback_FUNS[4]();
}


void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & 1 << 5) 		{EXTI->PR |= 1 << 5;   GP_IRQ_Callback_FUNS[5]();}
	if(EXTI->PR & 1 << 6) 		{EXTI->PR |= 1 << 6;   GP_IRQ_Callback_FUNS[6]();}
	if(EXTI->PR & 1 << 7) 		{EXTI->PR |= 1 << 7;   GP_IRQ_Callback_FUNS[7]();}
	if(EXTI->PR & 1 << 8) 		{EXTI->PR |= 1 << 8;   GP_IRQ_Callback_FUNS[8]();}
	if(EXTI->PR & 1 << 9) 		{EXTI->PR |= 1 << 9;   GP_IRQ_Callback_FUNS[9]();}
}


void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1 << 10) 		{EXTI->PR |= 1 << 10;   GP_IRQ_Callback_FUNS[10]();}
	if(EXTI->PR & 1 << 11) 		{EXTI->PR |= 1 << 11;   GP_IRQ_Callback_FUNS[11]();}
	if(EXTI->PR & 1 << 12) 		{EXTI->PR |= 1 << 12;   GP_IRQ_Callback_FUNS[12]();}
	if(EXTI->PR & 1 << 13) 		{EXTI->PR |= 1 << 13;   GP_IRQ_Callback_FUNS[13]();}
	if(EXTI->PR & 1 << 14) 		{EXTI->PR |= 1 << 14;   GP_IRQ_Callback_FUNS[14]();}
	if(EXTI->PR & 1 << 15) 		{EXTI->PR |= 1 << 15;   GP_IRQ_Callback_FUNS[15]();}
}




