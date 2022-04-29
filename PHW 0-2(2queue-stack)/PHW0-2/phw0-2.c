#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int queue1[SIZE], queue2[SIZE];
int queue1Front = -1, queue1Rear = -1;   //queue1's front, rear
int queue2Front = -1, queue2Rear = -1;     //queue2's front, rear
int top = -1; //virtual stack's top

//defensive coding: Check that the queue1 is full
int queue1_full() {
	if (queue1Rear >= SIZE - 1)
		return 1;
	return 0;
}

//defensive coding: Check that the queue1 is empty
int queue1_empty() {
	if (queue1Front == -1 || queue1Front > queue1Rear)
		return 1;
	return 0;
}

//description: enqueue the data in queue1
//input: data to append
//output: none
//virtual stack's top +1
void enqueue1(int data) {
	queue1[++queue1Rear] = data;
	top++;
	if (queue1Front == -1)
		queue1Front++;
}

//dequeue the data from queue1
//input: none
//output: data on queue1Front of the queue1
//virtual stack's top -1
int dequeue1() {
	int temp = queue1[queue1Front];
	queue1Front++;
	top--;
	return temp;
}
//----------------------------------------------Queue1 ∟∟∟∟

//defensive coding: Check that the queue2 is full
int queue2_full() {
	if (queue2Rear >= SIZE - 1)
		return 1;
	return 0;
}

//defensive coding: Check that the queue2 is empty
int queue2_empty() {
	if (queue2Front == -1 || queue2Front > queue2Rear)
		return 1;
	return 0;
}

//description: enqueue the data in queue2
//input: data to append
//output: none
void enqueue2(int data) {
	queue2[++queue2Rear] = data;
	if (queue2Front == -1)
		queue2Front++;
}

//dequeue the data from queue2
//input: none
//output: data on queue2Front of the queue2
int dequeue2() {
	int temp = queue2[queue2Front];
	queue2Front++;
	return temp;
}
//-----------------------------------------Queue2 ∟∟∟∟


int main(void) {

	int virtualStackMode = -1;

	while (virtualStackMode != 3) {
		printf("天天天天天天天天天天天天天天天天天天天天天天天天\nWrite the number  1: push, 2: pop, 3: exit\n");
		scanf("%d", &virtualStackMode);

		if (virtualStackMode == 1) { //virtual stack: push mode

			if (queue1_full() != 1) { //defensive coding
				int enqueueNumber;

				printf("Push the number: \n");
				scanf("%d", &enqueueNumber);

				enqueue1(enqueueNumber);

				
				printf("Virtual Stack: ");  //print the virtual Stack.

				if (queue1Rear == -1) {  //'queue1Rear is -1' mean virtual stack is empty
					printf("Stack is empty");
				}
				else {
					for (int i = queue1Front; i <= queue1Rear; i++) { //range of virtualstack same queue1Front ~ queue1Rear
						printf("%d ", queue1[i]);
					}
				}

				printf("\nTop = %d\n", top);
			}
			else {
				printf("Virtual stack is full. You must pop the value.\n");

			}
		}
		else if (virtualStackMode == 2) { //virtual stack: pop mode
			if (queue1_empty() != 1) { //defensive coding

				int dequeueNumber;

				if (queue1Rear == 0) { //If queue1 have one value, the program must not move it to queue2.
					dequeueNumber = dequeue1();

					queue1Front = -1; //initialize queue1
					queue1Rear = -1;
					queue2Front = -1;  //initialize queue2
					queue2Rear = -1;
					
				}
				else {
					for (int i = 0; i < queue1Rear; i++) {  //move the values from queue1 to queue2
						enqueue2(dequeue1());
						
					}
					
				

					dequeueNumber = dequeue1(); // pop the top value(virtual stack)

					queue1Front = -1; //initialize queue1
					queue1Rear = -1;  //initialize queue1

					for (int j = 0; j <= queue2Rear; j++) { //restore to queue1 original state
						enqueue1(dequeue2());
					}

					queue2Front = -1;  //initialize queue2
					queue2Rear = -1;  //initialize queue2
				}
				
				printf("Number from pop: %d\n", dequeueNumber);

				
				printf("Virtual Stack: ");  //print the virtual Stack.

				if (queue1Rear == -1) {  //'queue1Rear is -1' mean virtual stack is empty
					printf("Stack is empty");
				}
				else {
					for (int i = queue1Front; i <= queue1Rear; i++) { //range of virtualstack same queue1Front ~ queue1Rear
						printf("%d ", queue1[i]);
					}
				}

				printf("\nTop = %d\n", top);
			}
			else {
				printf("Virtual stack is empty! You must push the value.\n");
			}
		}
		else if (virtualStackMode == 3) {  //virtual stack: exit
			printf("Exit.");
		}
		else {
			printf("This virtual stack mode is invalid value. Write the valid number.\n");
		}
	}


	return 0;
}