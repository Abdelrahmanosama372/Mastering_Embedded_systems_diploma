/*
 * stm32f103x6_TIMER_2to5_driver.h
 *
 *
 *      Author: Abdelrahman osama
 */

#ifndef INC_STM32F103X6_TIMER_2TO5_DRIVER_H_
#define INC_STM32F103X6_TIMER_2TO5_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103x6_RCC_driver.h"
// this driver is made to be used as RTOS timer to produce periodic interrupts
// the cover functionality is UP and DOWN Counter

typedef struct
{
	uint16_t TIMER_Auto_Reload_preload_EN;  // specifies whether TIMx_ARR register is buffered or not
											// this parameter must be set based on @ref TIMER_Auto_Reload_preload_Enable/disable

	uint16_t TIMER_Mode;					// specifies whether Timer mode is  Edge-aligned mode or from Center-aligned modes
										    // this parameter must be set based on @ref TIMER_Modes

	uint16_t TIMER_Count_Direction; 		// specifies whether counter is used to count up or down
											// this parameter must be set based on @ref TIMER_Count_Directions

	uint16_t TIMER_operation_mode;		// specifies whether TIMER operate periodically or One Pulse Mode timer
										    // this parameter must be set based on @ref TIMER_operation_mode

	uint16_t TIMER_Update_REQ_Source;		// specifies the selection of the UEV(update event) event sources.
								    		// this parameter must be set based on @ref TIMER_Update_Request_Source

	uint16_t TIMER_Update_EN;				// specifies whether enable/disable UEV(update event) event generation
								 		    // this parameter must be set based on @ref TIMER_Update_EN

	uint16_t TIMER_Update_IRQ_EN;			// specifies whether to enable events to generate an update interrupt
	   	   	   	   	   	   	   	   	   	    // this parameter must be set based on @ref TIMER_Update_IRQ_EN

	void (*P_IRQ_Callback)(void);			// specifies the callback function to be executed on update interrupt generation

}TIM2_5_config;

//================================
//		Reference macros
//================================

// TIMER_Auto_Reload_preload_Enable/disable
#define TIMER_Auto_Reload_preload_Disable		(uint16_t)(0)			//TIMx_ARR register is not buffered
#define TIMER_Auto_Reload_preload_Enable      	(uint16_t)(1<<7)        //TIMx_ARR register is buffered

// TIMER_Modes
#define TIMER_Edge_aligned_Mode					(uint16_t)(0)          	    // The counter counts up or down depending on the direction bit(DIR)

#define TIMER_Center_aligned_Mode_1				(uint16_t)(1<<5)			// Output compare interrupt flags of channels
																			// configured in output (CCxS=00 in TIMx_CCMRx register) are set
																			// only when the counter is counting down.

#define TIMER_Center_aligned_Mode_2				(uint16_t)(1<<6)            // Output compare interrupt flags of channels
																			// configured in output (CCxS=00 in TIMx_CCMRx register) are set
																			// only when the counter is counting UP.

#define TIMER_Center_aligned_Mode_3				(uint16_t)(1<<5 || 1<<6)	// Output compare interrupt flags of channels
																			// configured in output (CCxS=00 in TIMx_CCMRx register) are set
																			// only when the counter is counting Up or down.

// TIMER_Count_Directions
#define TIMER_UP_Counter        (uint16_t)(0)                       // Counter used as up counter
#define TIMER_Down_Counter		(uint16_t)(1<<4) 					// Counter used as down counter


// TIMER_operation_mode
#define TIMER_Periodic_Mode_Enable       (uint16_t)(0)           // Counter is not stopped at update event
#define TIMER_One_Pulse_Mode_Enable      (uint16_t)(1<<3)		 // Counter stops counting at the next update event (clearing the bit CEN)


// TIMER_Update_Request_Source

#define TIMER_MUTI_Update_Request_Sources		(uint16_t)(0) 	    //Any of the following events generate an update interrupt or DMA request if enabled.
																	//These events can be:
																	//– Counter overflow/underflow
																	//– Setting the UG bit
																	//– Update generation through the slave mode controller

#define TIMER_OU_FLOW_Update_Request_Source	    (uint16_t)(1<<2) 	//Only counter overflow/underflow generates an update interrupt or DMA request if

// TIMER_Update_EN
#define TIMER_Update_Enable                     (uint16_t)(0)       // UEV(update event) enabled.

#define TIMER_Update_Disable                    (uint16_t)(1<<1)    // UEV disabled. The Update event is not generated, shadow registers keep their value
																    // (ARR, PSC, CCRx). However the counter and the prescaler are reinitialized if the UG bit is
																	// set or if a hardware reset is received from the slave mode controller.

// TIMER_Update_IRQ_EN
#define TIMER_Update_IRQ_Disable     (uint16_t)(0)      // Update interrupt disabled.
#define TIMER_Update_IRQ_Enable		 (uint16_t)(1)		// Update interrupt Enabled.

// TIMER Enable/Disable macros
#define TIMER_Counter_Disable        (uint16_t)(0)      // Counter enabled
#define TIMER_Counter_Enable		 (uint16_t)(1)		// Counter disabled

//=====================================================================================
//									APIs Prototypes
//=====================================================================================
void MCAL_Timer_init(TIM2_5_TypeDef *TIMx, TIM2_5_config *TIMx_config);
void MCAL_Timer_Update(TIM2_5_TypeDef *TIMx, TIM2_5_config *TIMx_config);
void MCAL_Timer_Deinit(TIM2_5_TypeDef *TIMx);
void MCAL_Timer_Start(TIM2_5_TypeDef *TIMx,uint32_t time_ms);
void MCAL_Timer_Stop(TIM2_5_TypeDef *TIMx);



#endif  /* INC_STM32F103X6_TIMER_2TO5_DRIVER_H_ */





