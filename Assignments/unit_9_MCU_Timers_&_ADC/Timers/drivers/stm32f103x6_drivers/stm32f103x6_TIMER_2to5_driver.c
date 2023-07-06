/*
 * stm32f103x6_TIMER_2to5_driver.c
 *
 *
 *      Author: Abdelrahman osama
 */

#include "stm32f103x6_TIMER_2to5_driver.h"

//=====================================================================================
//								Generic Variables
//=====================================================================================
TIM2_5_config G_TIM_Config[3];
uint16_t G_Counter_Val[3];


void MCAL_Timer_init(TIM2_5_TypeDef *TIMx, TIM2_5_config *TIMx_config)
{
	// Timer clock enable and configuration saving
	if (TIMx == TIM2)
	{
		RCC_TIM2_ENABLE();
		G_TIM_Config[0] = *TIMx_config;
	}

	else if (TIMx == TIM3)
	{
		RCC_TIM3_ENABLE();
		G_TIM_Config[1] = *TIMx_config;
	}

	else if (TIMx == TIM4)
	{
		RCC_TIM4_ENABLE();
		G_TIM_Config[2] = *TIMx_config;
	}

	uint16_t temp_reg = 0;

	// configure TIMER_Auto_Reload_preload configuration
	temp_reg |= TIMx_config->TIMER_Auto_Reload_preload_EN;

	// configure timer counting direction Up/Down
	temp_reg |= TIMx_config->TIMER_Count_Direction;

	// configure Timer mode
	temp_reg |= TIMx_config->TIMER_Mode;

	// configure TIMER One Pulse Mode Enable/Disable
	temp_reg |= TIMx_config->TIMER_operation_mode;

	// configure Timer Update status
	temp_reg |= TIMx_config->TIMER_Update_EN;

	// configure TImer Update request source
	temp_reg |= TIMx_config->TIMER_Update_REQ_Source;

	// clearing previous configuration in case of timer configuration update
	TIMx->CR1 &= ~(0x1FF);
	// initialize timer with the new configuration
	TIMx->CR1 |= temp_reg;

	// TIMER interrupt configuration
	TIMx->DIER &= ~(0x1);
	TIMx->DIER |= TIMx_config->TIMER_Update_IRQ_EN;

	// Enable the corresponding interrupt mask in the NVIC in case Interrupt is enabled in Timer configuration
	if (TIMx_config->TIMER_Update_IRQ_EN == TIMER_Update_IRQ_Enable)
	{
		if (TIMx == TIM2)
		{
			NVIC_IRQ28_TIM2_ENABLE;
		}

		else if (TIMx == TIM3)
		{
			NVIC_IRQ29_TIM3_ENABLE;
		}

		else if (TIMx == TIM4)
		{
			NVIC_IRQ30_TIM4_ENABLE;
		}
	}

}

void MCAL_Timer_Update(TIM2_5_TypeDef *TIMx, TIM2_5_config *TIMx_config)
{
	// Timer Initialization Updating
	MCAL_Timer_init(TIMx,TIMx_config);
}

void MCAL_Timer_Deinit(TIM2_5_TypeDef *TIMx)
{
	// TIMER Reset and disabling the corresponding interrupt mask in the NVIC
	if (TIMx == TIM2)
	{
		RCC_TIM2_RESET();
		NVIC_IRQ28_TIM2_DISABLE;
	}

	else if (TIMx == TIM3)
	{
		RCC_TIM3_RESET();
		NVIC_IRQ29_TIM3_DISABLE;
	}

	else if (TIMx == TIM4)
	{
		RCC_TIM4_RESET();
		NVIC_IRQ30_TIM4_DISABLE;
	}
}

void MCAL_Timer_Start(TIM2_5_TypeDef *TIMx,uint32_t time_ms)
{
	// temp variable to check if counter_val is huge to fit in the 16-bit counter register
	uint32_t temp_counter_val;

	// counter_val store the suitable counter register value
	uint16_t counter_val;

	// initial clock prescaler
	uint16_t clk_prescaler = 1;

	// storing the temp counter value on initial clk_prescaler
	temp_counter_val = ((MCAL_RCC_get_PCLK1(RCC)/1000)*time_ms);

	// check counter value exceed register size
	if (temp_counter_val > UINT16_MAX)
	{
		// increase clock prescaler by 1 to get the least clock prescaler that achieve the required time value
		clk_prescaler++;

		while ((temp_counter_val/clk_prescaler) > UINT16_MAX)
		{
			// increase clock prescaler by 1
			clk_prescaler++;
		}
	}

	// getting counter register value
	counter_val = ((uint16_t)(temp_counter_val/clk_prescaler)) - 1;

	// save the counter_val value to reload the counter in periodic timer operation mode
	if (TIMx == TIM2)
	{
		G_Counter_Val[0] = counter_val;
	}

	else if (TIMx == TIM3)
	{
		G_Counter_Val[1] = counter_val;
	}

	else if (TIMx == TIM4)
	{
		G_Counter_Val[2] = counter_val;
	}

	// configure counter_val value
	TIMx->CNT = counter_val;

	// configure clock prescaler
	// The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
	TIMx->PSC = clk_prescaler-1;

	// Timer enable
	TIMx->CR1 |= TIMER_Counter_Enable;

}

void MCAL_Timer_Stop(TIM2_5_TypeDef *TIMx)
{
	// TImer stop
	TIMx->CR1 &= ~(0x1); // CEN: Counter enable -> 0: Counter disabled

	// clearing counter value
	TIMx->CNT = 0x0;
}

// IRQs Handlers
void TIM2_IRQHandler(void)
{
	// update interrupt handling
	// UIF: Update interrupt flag -> 1: Update interrupt pending
	// clear UIF pending request
	TIM2->SR &= ~(0x1);

	// check on periodic timer operation
	if(G_TIM_Config[0].TIMER_operation_mode == TIMER_Periodic_Mode_Enable)
		// reload the counter
		TIM2->CNT = G_Counter_Val[0];

	// call the IRQ callback function
	G_TIM_Config[0].P_IRQ_Callback();
}

void TIM3_IRQHandler(void)
{
	// clear UIF pending request
	TIM3->SR &= ~(0x1);

	// check on periodic timer operation
	if(G_TIM_Config[1].TIMER_operation_mode == TIMER_Periodic_Mode_Enable)
		// reload the counter
		TIM3->CNT = G_Counter_Val[1];

	// call the IRQ callback function
	G_TIM_Config[1].P_IRQ_Callback();
}

void TIM4_IRQHandler(void)
{
	// clear UIF pending request
	TIM4->SR &= ~(0x1);

	// check on periodic timer operation
	if(G_TIM_Config[2].TIMER_operation_mode == TIMER_Periodic_Mode_Enable)
		// reload the counter
		TIM4->CNT = G_Counter_Val[2];

	// call the IRQ callback function
	G_TIM_Config[2].P_IRQ_Callback();
}
