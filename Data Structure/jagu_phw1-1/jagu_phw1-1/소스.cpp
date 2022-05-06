#include <stdio.h>
#include <stdlib.h>

int circular_queue[5];
int front = -1;
int rear = -1;
//initialization front and rear value

int queue_full() {//if queue is full, return true
	if (abs(front-rear) == 5) {//rear == front 
		
		return 1;
	}
	
	
	else {
		return 0;
	}

}


int queue_empty() {// if queue is empty, return true
	if (front == rear ) { //absolutely same

		return 1;
	}
	else {
		return 0;
	}

}


void enqueue(int num) {// insert number
	if (queue_full()) {

		printf("queue is overflow \n");//overflow warning
		exit(1);
	}
	else {
		

		rear++;
		circular_queue[rear % 5] = num; 
		//circular_queue array num max is 4 , so devide by 5

		
	}
	
}

int dequeue() {
	if (queue_empty()) {

		printf("queue is empty \n");//underflow warning
		return 0;
	}
	else {
		front++;
		return circular_queue[front % 5];
		//circular_queue array num max is 4 , so devide by 5
	}
	
}





int main() {
	
		enqueue(4);
		enqueue(25);
		dequeue();
		enqueue(6);
		dequeue();
		enqueue(10);
		enqueue(50);
		enqueue(28);
		enqueue(22);


	for (int i = 0; i < 5; i++) {

		printf("circular queue %d: value %d \n", i, circular_queue[i]);
	}//print circular queue array
	return 0;
}