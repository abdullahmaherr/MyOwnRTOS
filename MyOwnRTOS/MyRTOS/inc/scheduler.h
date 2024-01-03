/*============================================================================================
 * Module : Scheduler
 *
 * File Name : scheduler.h
 *
 * Author: Abdullah Maher
 *
 * Description : Scheduler
 *
 * Created on: Sep 1, 2023
 =============================================================================================*/
#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/

#include "cortex_mx_os_porting.h"

/*===============================================================================
 *                             Type Definitions     	                         *
 ================================================================================*/
typedef enum
{
	NO_ERROR,READY_FIFO_INIT_ERROR,TASK_EXCEED_STACK_BAOUNDARIES
}RTOS_ERROR_STATE;

typedef enum
{
	BLOCKING_DISABLED,BLOCKING_ENABLED
}BLOCKING_STATE;

typedef struct
{
	BLOCKING_STATE Task_Bloking;
	uint32_t Task_WaitingTicsCount;

}TASK_WAITING_TIME;

typedef enum
{
	SUSPEND,
	WAITING,
	READY,
	RUNNING
}TASK_STATE;

typedef struct
{
	uint8_t Task_Name[30];		/* Entered By The User */
	uint32_t Task_StackSize;	/* Entered By The User */
	uint8_t Task_Priority;		/* Entered By The User */
	void(*p_Task_Entery)(void);	/* Entered By The User */
	uint32_t Task_S_PSP;
	uint32_t Task_E_PSP;
	uint32_t* Task_Current_PSP;
	TASK_STATE Task_State;
	TASK_WAITING_TIME Task_WaitingTime;
}TASK_REF;
/*===============================================================================
 *               			          Macros 			                         *
 ================================================================================*/
#define MAX_NO_OF_TASKS					100				/* Static Configuration For Maximum Number Of Tasks */

#define MSP_SIZE						3072			/* Static Configuration For Main Stack Size */

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MYRTOS_Init.
 * Brief          : Function To Initialize The RTOS.
 * Parameter (in) : None.
 * Return         : Error State.
 * Note           : None																*/
RTOS_ERROR_STATE MYRTOS_Init(void);

/**===============================================================================
 * Function Name  : MYRTOS_StartRTOS.
 * Brief          : Function To Start The RTOS.
 * Parameter (in) : None.
 * Return         : Error State.
 * Note           : None																*/
RTOS_ERROR_STATE MYRTOS_StartRTOS(void);

/**===============================================================================
 * Function Name  : MYRTOS_CreateTask.
 * Brief          : Function To Create Task.
 * Parameter (in) : Pointer To Task Reference.
 * Return         : Error State.
 * Note           : None																*/
RTOS_ERROR_STATE MYRTOS_CreateTask(TASK_REF* task);

/**===============================================================================
 * Function Name  : MYRTOS_ActivateTask.
 * Brief          : Function To Activate Task.
 * Parameter (in) : Pointer To Task Reference.
 * Return         : Error State.
 * Note           : None																*/
RTOS_ERROR_STATE MYRTOS_ActivateTask(TASK_REF* task);

/**===============================================================================
 * Function Name  : MYRTOS_TerminateTask.
 * Brief          : Function To Terminate Task.
 * Parameter (in) : Pointer To Task Reference.
 * Return         : Error State.
 * Note           : None																*/
RTOS_ERROR_STATE MYRTOS_TerminateTask(TASK_REF* task);

/**===============================================================================
 * Function Name  : MYRTOS_WaitTask.
 * Brief          : Function To Block Task For a Certain Time.
 * Parameter (in) : Pointer To Task Reference.
 * Parameter (in) : No. of Desired Blocked Ticks.
 * Return         : Error State.
 * Note           : None																*/
RTOS_ERROR_STATE MYRTOS_WaitTask(TASK_REF* task, uint32_t a_BlockTicks);

#endif /* INC_SCHEDULER_H_ */
