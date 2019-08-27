#include <pthread.h>
#include <stdio.h>

/* Add a number with its own number and return the result*/

void* add (void* arg)
{
	int n = *((int*) arg);
	int result;
	
	result = n + n;

	return (void*) result;
}


/* Multiply a number with its own number and return the result*/

void* multiply (void* arg)
{
	int n = *((int*) arg);
	int result;
	
	result = n * n;

	return (void*) result;
}



/* The main program. */

int main ()
{
	pthread_t thread1_id;
	pthread_t thread2_id;

	int number = 5;
	void *add_result, *mul_result;

	/* Create a new thread to add a number with its own number. */
	/* Insert Your Code #1 */

	/* Create a new thread to add a number with its own number. */
	/* Insert Your Code #2 */

	/* Make sure the first thread has finished. */
	pthread_join (thread1_id, &add_result);
	/* Make sure the second thread has finished. */
	pthread_join (thread2_id, &mul_result);

	printf("The result of add is %d\n", add_result);
	printf("The result of multiply is %d\n", mul_result);

	/* Now we can safely return. */
	return 0;
}
