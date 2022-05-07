#include <stdio.h>

int queue1[10];
int queue2[10];
int front1 = -1;
int rear1 = -1;
int front2 = -1;
int rear2 = -1;
//initialize queue1,2, and front 1,2 and rear 1,2 

void enqueue1(int num) {// in queue1 add value
	
	if (front1 == -1) {
		front1 = 0;
	}

	rear1++;
	queue1[rear1] = num;
	
	
}

void enqueue2(int num) {// in queue2 add value

	if (front2 == -1) {
		front2 = 0;
	}

	rear2++;
	queue2[rear2] = num;


}

int dequeue1() {// in queue1 delete most olddest value
	
	front1++;
	
	return queue1[front1-1];
}

int dequeue2() {// in queue2 delete most olddest value
	
	front2++;

	return queue2[front2-1];
}

int queue_full() {//check queue is overflow
	if (rear1 == 9) {
		printf("queue1 is full");
		return -1;
	}
	else {
		return 0;
	}

}

int queue_empty() {//check queue is underflow
	if (rear1 == -1) {
		printf("queue1 is empty");
		return -1;
	}
	else {
		return 0;
	}

}

int main() {
	if (!queue_full()) {//if queue is full, reject insert
		enqueue1(3);
		enqueue1(4);
		enqueue1(25);
		enqueue1(6);

	}


	if (!queue_full() && !queue_empty()) {
		enqueue2(dequeue1());
		enqueue2(dequeue1());
		enqueue2(dequeue1());//dequeue from old one to recent one, so queue1 [0],[1],[2] delete, and insert in queue2 [0],[1],[2] 
		dequeue1();// only queue1 delete [3]
	}
	

	
	if (!queue_full() && !queue_empty()) {
		enqueue1(dequeue2());
		enqueue1(dequeue2());
		enqueue1(dequeue2()); //queue2[0], [1], [2] delete, and insert in queue1 [0], [1], [2]

	}

	for (int i = front1; i <= rear1; i++) {

		printf("[%d] stack value: %d\n", i, queue1[i]);//print what value is in queue
	}



	return 0;
}