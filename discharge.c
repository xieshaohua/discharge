#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *arg)
{
	int i;
	double seed = 1.01;
	(void *)arg;
	printf("thread created...\n");
	while(1) {
		double sum = 0;
		double *p = malloc(1024*sizeof(double));
		if (!p) {
			printf("malloc error");
			exit(-1);
		}
		for(i = 0; i < 1024; i++) {
			p[i] = p[i] * seed;
			sum = sum + p[i];
		}
		sum = sum / 1024;
		seed = seed * sum;
		free(p);
	};
}


int main(int argc, char *argv[])
{
	int i, err;
	pthread_t tid[10];

	argc = argc;
	argv = argv;
	for (i = 0; i < 10; i++) {
		err = pthread_create(&tid[i], NULL, thread, NULL);
		if (err != 0) {
			printf("%d thread create error!\n", i);
			return -1;
		}
	}
	while(1) {
		printf("good\n");
		sleep(10);
	}
	return 0;
}
