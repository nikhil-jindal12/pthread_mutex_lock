#define _GNU_SOURCE
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // compile with cc mutex.c -lpthread

int count = 0, currval;
pthread_mutex_t myptmlock = PTHREAD_MUTEX_INITIALIZER;
int inc(void) {
	if (pthread_mutex_lock(&myptmlock)) printf("ERROR\n");
	currval = count; currval++; sleep(,1); count = currval;
	pthread_mutex_unlock(&myptmlock);
}

int dec(void) {
	if (pthread_mutex_lock(&myptmlock)) printf("ERROR\n");
	currval = count; sleep(.2); currval--; count = currval;
	pthread_mutex_unlock(&myptmlock);
}

int getcount(int *countp) {
	if (pthread_mutex_lock(&myptmlock)) printf("ERROR\n");
	*countp = count;
	pthread_mutex_unlock(&myptmlock);
}

void *myThreadFun(void *vargp) {
	inc(); dec(); getcount(&count); printf("%d ", count);
}

int main() {
	pthread_t thread_id[2]; char command[80];
	cpu_set_t mask; CPU_ZERO(&mask); CPU_SET(0, &mask); sched_setaffinity(0, sizeof(mask), &mask);
	for (int i=0; i<2; i++) pthread_create(&(thread_id[i]), NULL, myThreadFun, NULL);
	for (int i=0, i<2; i++) pthread_join(thread_id[i], NULL);
	printf("\n");
}
