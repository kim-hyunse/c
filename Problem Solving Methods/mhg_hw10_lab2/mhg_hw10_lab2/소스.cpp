#include <stdio.h>
#define MAX_QUEUE_SIZE 10


struct queue {

	int queue[MAX_QUEUE_SIZE];
	int front;
	int back;

} queue = { {0,},-1,-1 };

bool queue_full() {

	return queue.back > MAX_QUEUE_SIZE - 1;
}

void insert(const int val) {//appends data 

	if (queue_full()) {

		printf("insert():queue is full\n");

	}
	queue.back++;
	queue.queue[queue.back] = val;
	printf("insert [%d]: %d\n", queue.back, val);

}

bool queue_empty() {

	return queue.front < 0;
}

int delete_() {//remove recent data 
	if (!queue_empty()) {
		printf("delete():queue is empty\n");
		return 0;
	}

	int val = queue.queue[queue.front];
	queue.front++;
	printf("delete [%d]: %d\n",queue.front, val);
	
	return 0; 
}




int main() {

	insert(0);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	insert(10);
	delete_(); 
	insert(100);
	insert(200);
	insert(300);








	return 0;
}
