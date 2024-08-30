#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

/* Wait on a binary semaphore.
Block until the semaphore value is positive, then
decrement it by 1. */
int binary_semaphore_wait (int semid)
{
	struct sembuf operations[1];
	
	/* Use the first (and only) semaphore.*/
	operations[0].sem_num = 0;

	/* Decrement by 1. */
	operations[0].sem_op = -1;

	/* Permit undo’ing. */
	operations[0].sem_flg = SEM_UNDO;
	return semop (semid, operations, 1);
}

/* Post to a binary semaphore: increment its value by 1.
This returns immediately. */
int binary_semaphore_post (int semid)
{
	struct sembuf operations[1];
	
	/* Use the first (and only) semaphore.*/
	operations[0].sem_num = 0;
	
	/* Increment by 1. */
	operations[0].sem_op = 1;
	
	/* Permit undo’ing. */
	operations[0].sem_flg = SEM_UNDO;
	
	return semop (semid, operations, 1);
}
