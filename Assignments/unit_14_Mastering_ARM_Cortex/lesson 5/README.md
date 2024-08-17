# LAB topic
the lab is about simulating an OS schedular that switches between taskA and taskB

# LAB simulation in keil
- system start with taskA until an interrupt occur to switch to taskB
- first we store stack of taskA in PSP
![Alt text](./store_taskA_stack_in_PSP.png)

- switch the sp to PSP
![Alt text](./switch_sp_to_PSP.png)

- switch to unprivileged mode
![Alt text](./switch_to_unprivillage_mode1.png)

- run taskA and get it's return in R0=5 (3 + 2)
![Alt text](./return_of_task_A.png)

- calling SVC instruction to switch to privillage mode in the SVC handler
![Alt text](./switch_to_privillage_mode.png)

- switching sp from PSP to MSP
![Alt text](./switch_sp_to_MSP.png)


- when EXTI occurs on PB9 we switch to taskB 
![Alt text](./switch_task_flag_at_ISR.png)

- first we store stack of taskB in PSP
![Alt text](./store_taskB_stack_in_PSP.png)

- switch the sp to PSP
![Alt text](./switch_sp_to_PSP2.png)

- switch to unprivileged mode
![Alt text](./switch_to_privillage_mode2.png)

- run taskB and get it's return in R0=1 (3 - 2)
![Alt text](./return_of_task_B.png)

- calling SVC instruction to switch to privillage mode in the SVC handler
![Alt text](./switch_to_privillage_mode2.png)

- switching sp from PSP to MSP
![Alt text](./switch_sp_to_MSP.png)

