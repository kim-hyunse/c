#include <stdio.h>

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int num) {
	rear++;
	queue[rear] = num;
	front = 0;
	printf("queue rear[%d] value %d \n", rear, num);
}

void dequeue() {
	front++;
	printf("queue front[%d]  \n", front);
}

int queue_full() {
	if (rear == 9) {
		printf("queue is full");
		return -1;
	}
	else {
		return 0;
	}

}

int queue_empty() {
	if (rear == -1) {
		printf("queue is empty");
		return -1;
	}
	else {
		return 0;
	}

}

int main() {
	if (!queue_full()) {
	enqueue(3);
	enqueue(4);
	enqueue(25);
	enqueue(6);


	}
	
	
	if (!queue_empty()) {
		
	dequeue();
	dequeue();


	}
	
	for (int i = front; i <= rear; i++) {

		printf("%d \n", queue[i]);
	}
	return 0;
}