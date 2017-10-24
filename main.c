// Alicja Kołodziejska

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_fun(void *ptr) {
	printf("%s\n", (char *) ptr);
	pthread_exit(NULL);
}

int main() {
	const char *s1 = "Thread 1.", *s2 = "Thread 2.";
	pthread_t t1, t2;
	int e1, e2;
	
	e1 = pthread_create(&t1, NULL, thread_fun, (void*) s1);
	if(e1) {
		printf("Error creating Thread 1.: %d\n", e1);
		exit(1);
	}
	e2 = pthread_create(&t2, NULL, thread_fun, (void*) s2);
	if(e2) {
		printf("Error creating Thread 2.: %d\n", e2);
		exit(1);
	}
	
	e1 = pthread_join(t1, NULL);
	if(e1) {
		printf("Error joining Thread 1.: %d\n", e1);
		exit(1);
	}
	e2 = pthread_join(t2, NULL);
	if(e2) {
		printf("Error joining Thread 2.: %d\n", e2);
		exit(1);
	}
	
	printf("Finished.\n");
	pthread_exit(NULL);
	
}
