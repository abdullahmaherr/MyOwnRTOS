/**********************************************************************************************
 * Module : RTOS FIFO
 *
 * File Name : FIFO.c
 *
 * Author: Abdullah Maher
 *
 * Description :
 *
 * Created on: Aug 8, 2023
 ***********************************************************************************************/

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/
#include"rtos_fifo.h"



/*===============================================================================
 *                              API Definitions                                  *
 ================================================================================*/

/*
 * Description : Function To Initializing FIFO
 * */
FIFO_STATE FIFO_init(FIFO_t *fifo, DATA_TYPE_t *buff, uint8_t length)
{
	/* FIFO Is NULL */
	if(buff == NULL_PTR)
	{
		return 	FIFO_NULL;
	}

	/* Assign FIFO */
	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	fifo->length = length;
	fifo->count = 0;


	return FIFO_NO_ERROR;
}


/*
 * Description : Function To Add Element in FIFO
 * */
FIFO_STATE FIFO_enqueue(FIFO_t *fifo, DATA_TYPE_t item)
{
	/* FIFO Is NULL */
	if(!(fifo->base) || !(fifo->head) || !(fifo->tail))
	{
		return 	FIFO_NULL;
	}

	/* FIFO Is FULL */
	if(fifo->count == fifo->length)
	{
		return FIFO_FULL;
	}

	/* Add Item To FIFO */
	*(fifo->tail) = item;
	fifo->count++;

	/* Circular Buffer */
	if((uint32_t)fifo->tail == ((uint32_t)fifo->base + (4 * fifo->length) - 4))
	{
		fifo->tail = fifo->base;
	}
	else
	{
		fifo->tail++;
	}

	return FIFO_NO_ERROR;
}


/*
 * Description : Function To Remove Element From FIFO
 * */
FIFO_STATE FIFO_dequeue(FIFO_t *fifo, DATA_TYPE_t *item)
{
	/* FIFO Is NULL */
	if(!(fifo->base) || !(fifo->head) || !(fifo->tail))
	{
		return 	FIFO_NULL;
	}

	/* FIFO Is Empty; */
	if(fifo->count == 0)
	{
		return FIFO_EMPTY;
	}

	/* Remove Item From FIFO */
	*item = *(fifo->head);
	fifo->count--;

	/* Circular Buffer */
	if((uint32_t)fifo->head == ((uint32_t)fifo->base + (4 * fifo->length) - 4))
	{
		fifo->head = fifo->base;
	}
	else
	{
		fifo->head++;
	}


	return FIFO_NO_ERROR;
}

FIFO_STATE FIFO_IsFull(FIFO_t *fifo)
{
	/* FIFO Is NULL */
	if(!(fifo->base) || !(fifo->head) || !(fifo->tail))
	{
		return 	FIFO_NULL;
	}

	/* FIFO Is FULL */
	if(fifo->count == fifo->length)
	{
		return FIFO_FULL;
	}

	return FIFO_IS_NOT_FULL;
}
