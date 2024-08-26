
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6_gpio_driver.h"
#include "stm32f103x6_EXTI_driver.h"
#include "stm32f103x6.h"

#define OS_ADD_TO_PSP(add)  __asm("MOV R0, %0 \t\n MSR PSP, R0": : "r"(add))

#define OS_SWITCH_SP_TO_PSP __asm("MRS R0, CONTROL \t\n ORR R0, #0x2 \t\n MSR CONTROL, R0");
#define OS_SWITCH_SP_TO_MSP __asm("MRS R0, CONTROL \t\n AND R0, #0x5 \t\n MSR CONTROL, R0");

#define Switch_To_UnPrivillageMode __asm("NOP \t\n \
										  MRS r3, CONTROL \t\n \
										  ORR r3, 0x1 \t\n \
										  MSR CONTROL, r3")

#define Switch_To_PrivillageMode __asm("NOP \t\n \
										MRS r3, CONTROL \t\n \
										LSR r3, 0x1 \t\n \
										LSL r3, 0x1 \t\n \
										MSR CONTROL, r3")


#define OS_GENERATE_EXCEPTION    __asm("SVC #0x3");


#define SCB_ICSR 				((uint32_t *)0xE000ED04)
#define ICSR_PendSVSET_Msk    	28
#define ICSR_PendSVCLR_Msk  	27

void OS_SVC(int *stackFrame);
int OS_SVC_Set(int a, int b, unsigned char SVC_ID);

int main(void)
{
	//add
	OS_SVC_Set(1,3,0);

	//subtract
	OS_SVC_Set(5,2,1);

	//multiply
	OS_SVC_Set(3,4,2);

	//make pendsv exception
	OS_SVC_Set(3,4,3);

	while(1)
	{

	}
}

int OS_SVC_Set(int a, int b, unsigned char SVC_ID)
{
	switch(SVC_ID) {
		case 0:
			__asm("svc #0x00");
			break;
		case 1:
			__asm("svc #0x01");
			break;
		case 2:
			__asm("svc #0x02");
			break;
		case 3:
			__asm("svc #0x03");
			break;
	}

	int result;
	__asm ("mov %0, r0" : "=r" (result));
	return result;
}

__attribute ((naked)) void SVC_Handler()
{
	asm("tst lr , #4 \n\t"
		"ITE EQ \n\t"
		"mrseq r0, MSP \n\t"
		"mrsne r0, PSP \n\t"
		"b OS_SVC");
}


__attribute ((naked)) void PendSV_Handler()
{
	*SCB_ICSR |= 1 << ICSR_PendSVCLR_Msk;
}


void OS_SVC(int *stackFrame)
{
	unsigned char svc_number;
	svc_number = *((unsigned char *)((unsigned char *)stackFrame[6] - 2));
	int a = stackFrame[0];
	int b = stackFrame[1];

	switch(svc_number) {
		case 0:
			stackFrame[0] = a + b;
			break;
		case 1:
			stackFrame[0] = a - b;
			break;
		case 2:
			stackFrame[0] = a * b;
			break;
		case 3:
			*SCB_ICSR = 1 << ICSR_PendSVSET_Msk;
			break;
	}

}
