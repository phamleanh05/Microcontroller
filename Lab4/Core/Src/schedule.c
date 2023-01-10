#include "main.h"
#include "schedule.h"

sTask SCH_tasks_G [SCH_MAX_TASKS ] ;

void SCH_Init ( void ) {
	 unsigned char i ;
	 for ( i = 0; i < SCH_MAX_TASKS; i++) {
		 SCH_Delete_Task ( i ) ;
	 }
}

void SCH_Update ( void ) {
	if ( SCH_tasks_G [ will_exercute_index ] . pTask ){
		if ( SCH_tasks_G [ will_exercute_index ] . Delay == 0 ) {
			SCH_tasks_G [ will_exercute_index ] . RunMe = 1;
			if ( SCH_tasks_G [ will_exercute_index  ] . Period ) {
											 // Schedule periodic tasks to run again
				SCH_tasks_G [ will_exercute_index  ] . Delay = SCH_tasks_G [ will_exercute_index ] . Period ;
			}
		}
		else {
			SCH_tasks_G [ will_exercute_index ].Delay -= 1;
			min_task_delay_update++;
		}
	}
 }

unsigned char SCH_Add_Task ( void ( * pFunction ) ( ) , unsigned int DELAY, unsigned int PERIOD)
{
	 unsigned char Index = 0;
	 // Fi r s t find a gap in the array ( i f there i s one)
	 while ( ( SCH_tasks_G [ Index ] . pTask != 0 ) && ( Index < SCH_MAX_TASKS) )
	 {
		 Index++;
	 }
	 // Have we reached the end o f the l i s t ?
	 if ( Index == SCH_MAX_TASKS)
	 {
		 // Task l i s t i s f u l l
		 // Set the global e r ro r v a ri abl e
//		 Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		 // Also return an e r ro r code
		 return SCH_MAX_TASKS;
	 }
	 // I f we ’re here , there i s a space in the task array
	 SCH_tasks_G [ Index ] . pTask = pFunction ;
	 SCH_tasks_G [ Index ] . Delay = DELAY;
	 SCH_tasks_G [ Index ] . Period = PERIOD;
	 SCH_tasks_G [ Index ] .RunMe = 0;
	 // return posi tion o f task ( to allow l a t e r dele tion )
	 return Index ;
}

unsigned char min_Task (void ){
	unsigned char min = 0;
	uint32_t min_value = SCH_tasks_G [ 0 ].Delay;
	unsigned char Index ;
	for ( Index = 0; Index < SCH_MAX_TASKS; Index++){
		if(SCH_tasks_G [ Index ] . Delay < min_value &&  SCH_tasks_G [ Index ] . pTask) {
			min = Index;
		}
	}
	return min;
}
void SCH_Dispatch_Tasks ( void )
{
	if(SCH_tasks_G [ will_exercute_index ] .RunMe > 0){
		( * SCH_tasks_G [ will_exercute_index ] . pTask ) ( ) ;
		SCH_tasks_G [ will_exercute_index ] .RunMe -= 1;
		if ( SCH_tasks_G [ will_exercute_index ] . Period == 0 )
		{
			SCH_Delete_Task ( will_exercute_index ) ;
		}

		unsigned char Index ;
				 // NOTE: c alcul a tions are in *TICKS* ( not milliseconds )
		for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
					 // Check i f there i s a task a t t hi s loca tion
			if ( SCH_tasks_G [ Index ] . pTask &&  Index != will_exercute_index) {
				SCH_tasks_G [ Index ].Delay -= min_task_delay_update;
			}
		}

		will_exercute_index = min_Task();
		min_task_delay_update = 0;
	}

	//min_task_delay_update;


//	 unsigned char Index ;
//	 // Dispatches (runs ) the next task ( i f one i s ready )
//	 for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
//		 if ( SCH_tasks_G [ Index ] .RunMe > 0 ) {
//			 ( * SCH_tasks_G [ Index ] . pTask ) ( ) ; // Run the task
//			 SCH_tasks_G [ Index ] .RunMe -= 1; // Reset / reduce RunMe fl a g
//			 // Periodic tasks will au toma tically run again
//			 // − i f t hi s i s a ’one shot ’ task , remove i t from the array
////			 if ( SCH_tasks_G [ Index ] . Period == 0 )
////			 {
////				 SCH_Delete_Task ( Index ) ;
////			 }
//		 }
//
//	 }
////	 // Report system s t a tus
////	 SCH_Report_Status ( ) ;
////	 // The scheduler en ters i dl e mode a t t hi s point
////	 SCH_Go_To_Sleep ( ) ;
}

unsigned char SCH_Delete_Task ( const unsigned int TASK_INDEX) {
	 unsigned char Return_code =0;
	 SCH_tasks_G [TASK_INDEX ] . pTask = 0x0000 ;
	 SCH_tasks_G [TASK_INDEX ] . Delay = 0;
	 SCH_tasks_G [TASK_INDEX ] . Period = 0;
	 SCH_tasks_G [TASK_INDEX ] .RunMe = 0;
	 return Return_code ; // return s t a tus
}
