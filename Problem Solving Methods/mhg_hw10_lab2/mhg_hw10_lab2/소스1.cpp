/*#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

struct QUEUE {

	int front;
	int back;
	struct QUEUE* next;

};

bool queue_full() {
	struct QUEUE queue = {-1,-1};
	return queue.back > MAX_QUEUE_SIZE - 1;
}

void insert(const int val) {//appends data 
	struct QUEUE queue = { -1, -1 };
	if (queue_full()) {

		printf("insert():queue is full\n");

	}
	queue.back++;
	int num = 0;
	queue.back = val;
	num++;
	printf("insert [%d]: %d\n", num, val);
	queue.next = &queue;


}

bool queue_empty() {
	struct QUEUE queue = { -1, -1 };
	return queue.front < 0;
}

int delete_() {//remove first data 
	struct QUEUE queue = { -1, -1 };;
	if (!queue_empty()) {
		printf("delete():queue is empty\n");
		return 0;
	}
	int val =0;
	val++;
	printf("delete [%d]: %d\n", val, queue.front);
	queue.front++;


	return 0;
}




int main() {

	struct QUEUE* queue;
	queue = (struct QUEUE*)malloc(10 * sizeof(struct QUEUE));
	
	if (queue == NULL) {
		printf("fail to malloc");
		exit(1);
	}

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	insert(10);
	insert(11);
	delete_();
	delete_();


	return 0;
}*/