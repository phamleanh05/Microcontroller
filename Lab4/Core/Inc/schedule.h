typedef struct {
	// Pointer to the task (must be a ’ void ( void ) ’ function )
	void ( * pTask ) ( void ) ;
	// Delay ( ti c k s ) un til the function will ( next ) be run
	uint32_t Delay ;
	// In t e r v al ( ti c k s ) between subsequent runs .
	uint32_t Period ;
	// Incremented (by scheduler) when task i s due to execute
	uint8_t RunMe;
	//This i s a hin t to solve the question below .
	uint32_t TaskID ;
} sTask ;

 // MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

extern sTask SCH_tasks_G [SCH_MAX_TASKS ] ;

void SCH_Init ( void );
void SCH_Update ( void );
unsigned char SCH_Add_Task ( void ( * pFunction ) ( ) , unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks ( void );
unsigned char SCH_Delete_Task ( const unsigned int TASK_INDEX);
