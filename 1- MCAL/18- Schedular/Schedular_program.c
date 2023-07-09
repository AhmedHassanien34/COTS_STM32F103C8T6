/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    7 APRIL 2023	            			*************/
/**************************		Layer:   MHAL								   	*************/
/**************************		SWC:	 SCHEDULAR								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************************************************************************************/
/* Include Interface Files in MCAL                                                          */
/********************************************************************************************/
#include "GPIO_interface.h"
#include "STK_interface.h"


static task_t  Tasks[3];

void createTask(void(*ptr)(void),uint8 priority, uint32 periodicty){


	Tasks[priority].task_periority = priority;

	Tasks[priority].task_periodicity = periodicty;

	Tasks[priority].task_ptr = ptr;


//	task_type * temp =  tasks_list;
//	if(tasks_list == NULL_PTR){
//
//		tasks_list = malloc(sizeof(task_type));
//		tasks_list->task_ptr = ptr;
//		tasks_list->next = NULL_PTR;
//
//	}
//	else{
//
//		while(temp->next != NULL_PTR){
//
//			temp = temp->next;
//		}
//
//		temp->next = malloc(sizeof(task_type));
//		temp->next->task_ptr = ptr;
//		temp->next->next = NULL_PTR;
//	}

}
//create task(pointer to function ,priotity, periodicty)

void schaduelar(void){

	for(int i =0 ; i<3 ; i++){

		Tasks[i].task_ptr();
		STK_voidSetBusyWait(Tasks[i].task_periodicity);
}

}
//start schaduelar
/********************************************************************************************/
/*   END OF FILE: LED_program.c                                                             */
/********************************************************************************************/
