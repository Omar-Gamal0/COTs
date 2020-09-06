/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 05 September 2020						*/
/************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

#define TASK_READY				1			/* Macro representing Task state: Ready */
#define TASK_SUSPENDED			0			/* Macro representing Task state: Suspended */

/* SOS_voidCreatTask --> Create a new task 																						*/
/* I/P: - Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 						* Type: u8
 * 		- Cpy_u16Periodicity: 	* Periodicity of the task (Represents how frequent will the task happen [Represented by number of ticks])
 * 								* Type: u16
 * 		- Cpy_u16InitialDelay: 	* InitialDelay of the task
 * 								* Type: u16
 * 		- ptr: 	* Address of the function of the task (The function that would be Called when the task occurs)
 * 				* Type: Pointer to function (Return type: void & Argument: void)
  																																*/
/* O/P: void 																													*/
void SOS_voidCreatTask(u8 Cpy_u8TaskID, u16 Cpy_u16Periodicity, u16 Cpy_u16InitialDelay, void (*ptr)(void));
/********************************************************************************************************************************/

/* SOS_voidStart --> Initializes STK and Calls the Scheduler function periodically every tick 	*/
/* I/P: void																					*/
/* O/P: void																					*/
void SOS_voidStart(void);
/************************************************************************************************/

/* SOS_voidSuspendTask --> Suspends a task														*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*/
/* O/P: void																					*/
void SOS_voidSuspendTask(u8 Cpy_u8TaskID);
/************************************************************************************************/

/* SOS_voidResumeTask --> Resumes a task														*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*/
/* O/P: void																					*/
void SOS_voidResumeTask(u8 Cpy_u8TaskID);
/************************************************************************************************/

/* SOS_voidDeleteTask --> Deletes a task														*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*/
/* O/P: void																					*/
void SOS_voidDeleteTask(u8 Cpy_u8TaskID);
/************************************************************************************************/

/* SOS_u8GetTaskState --> Gets State of a task													*/
/*I/P: Cpy_u8TaskID: * ID of the task (Represents its index in the array of structs: OS_Tasks)
 * 					 * Type: u8
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*/
/* O/P: State of a task (Return type u8)														*/
u8 SOS_u8GetTaskState(u8 Cpy_u8TaskID);
/************************************************************************************************/

#endif
