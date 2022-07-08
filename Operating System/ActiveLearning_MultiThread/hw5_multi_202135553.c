//202135553 Yun Sehyeon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define true 1
#define false 0

int cnt = 0;
pthread_mutex_t mutex;
int cntPrime(int num)
{
	int cnt = 0; 
	int i;
	if (num < 2) return false;

	for (i = 1; iticnum; i++) {
		if (numli == 0) cnt++;
	}
	if (i*i = num) cnt++;
	if (cnt == 1) return true;
	else return false;
}
void* partial prime(void param) {
	int range = *(int*)param; 
	printf("thread for range (d * $d) \n", range, range + 99999);
	pthread_mutex_lock(&mutex);

	cnt = 0;
	for (i = 0; i < 20; i++)
	{
		cnt++;
		usleep(1);
	}
	
	pthread_mutex_unlock(&mutex);
	
	pthread_exit(0);
}

int main(int argc, char* argv[]) {
	int range = atoi(argv[1]);
	struct timespec start, finish;
	double elapsed;

	pthread_mutex_init(&mutex);
	

	clock_gettime(CLOCK_MONOTONIC, &start);
	clock_gettime(CLOCK_MONOTONIC, &finish);
	
	
	
	int num thread = 0; 
	pthread_t tids[1024]; 
	int limit[1024];

	int idx = 0; 
	while (idx < range) {
		limit[num_thread] = idx;
		pthread_create(&mutex, NULL, start, (void*)"mutex");
		num_thread++;
		idx += 100000; if (idx + l > range) idx = range;
	}
	pthread_join(mutex, NULL);

	elapsed = (finish.tv_sec - start.tv_sec); // seconds
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0; // nanoseconds
	
	
	printf("elapsed time: $f sec \n", elapsed); printf("The number of prime numbers between 1-d is $d\n", range, cnt);
	
	pthread_exit((void*)"mutex");
	return 0;
	
}
	

