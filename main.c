#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fun(void *ptr) {
	//sleep(1);
	printf("%s\n", (char *) ptr);
	pthread_exit(NULL);
}

int main() {
	const char *m1 = "Thread 1.";
	const char *m2 = "Thread 2.";
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, thread_fun, (void*) m1));		
	pthread_create(&t2, NULL, thread_fun, (void*) m2);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Finished\n");
	pthread_exit(NULL);
	
}
