#include <stdio.h>
#include <pthread.h>

void *thread(void *arg)
{
	printf("thread created...\n");
	while(1) {};
}

int main(int argc, char *argv[])
{
	int i, err;
	pthread_t tid[10];

	for (i = 0; i < 10; i++) {
		err = pthread_create(&tid[i], NULL, thread, NULL);
		if (err != 0) {
			printf("%d thread create error!\n", i);
			return -1;
		}
	}
	while(1) {
		printf("good\n");
		sleep(5);
	}
	return 0;
}
