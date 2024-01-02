/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core_cm3.h"

#include "stm32f103c8.h"
#include "stm32f103c8_rcc_driver.h"
#include "stm32f103c8_gpio_driver.h"
#include "stm32f103c8_exti_driver.h"

#include "scheduler.h"

/*===============================================================================
 *                       		 	Macros			                             *
 ================================================================================*/





/*===============================================================================
 *                              Global Variables                                 *
 ================================================================================*/

TASK_REF task1,task2,task3;
uint8_t Task1_Led, Task2_Led, Task3_Led;

/*===============================================================================
 *     		       		 	ISR Functions Definition 		                     *
 ================================================================================*/


/*===============================================================================
 *                                Application                                    *
 ================================================================================*/
void Task3_Fun(void)
{
	while(1)
	{
		Task3_Led ^= 1;
	}
}

void Task2_Fun(void)
{
	while(1)
	{
		Task2_Led ^= 1;
	}
}

void Task1_Fun(void)
{
	while(1)
	{
		Task1_Led ^= 1;
	}
}

void System_Init(void)
{	

	/* Initialize HardWare */
	MyRTOS_HW_Init();

	/* Initialize The RTOS */
	MYRTOS_Init();

	/* Initialize The Tasks */

	strcpy(task1.Task_Name,"TASK_1");
	task1.Task_StackSize = 512;
	task1.Task_Priority = 1;
	task1.p_Task_Entery = Task1_Fun;
	MYRTOS_CreateTask(&task1);

	strcpy(task2.Task_Name,"TASK_2");
	task2.Task_StackSize = 512;
	task2.Task_Priority = 1;
	task2.p_Task_Entery = Task2_Fun;
	MYRTOS_CreateTask(&task2);

	strcpy(task3.Task_Name,"TASK_3");
	task3.Task_StackSize = 512;
	task3.Task_Priority = 1;
	task3.p_Task_Entery = Task3_Fun;
	MYRTOS_CreateTask(&task3);

	MYRTOS_ActivateTask(&task1);
	MYRTOS_ActivateTask(&task2);
	MYRTOS_ActivateTask(&task3);



	MYRTOS_StartRTOS();

}



int main(void)
{
	/* Function To Initiate The System (RTOS,HW,RCC) */
	System_Init();

	while(1)
	{

	}
}
