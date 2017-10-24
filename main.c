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
	
	pthread_create(&t1, NULL, thread_fun, (void*) s1);
	pthread_create(&t2, NULL, thread_fun, (void*) s2);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("Finished\n");
	pthread_exit(NULL);
	
}
