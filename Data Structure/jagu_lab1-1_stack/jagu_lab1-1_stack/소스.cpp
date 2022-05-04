#include <stdio.h>


int stack[10];
int top = -1;

void push(int num) {
	
	top++;
	stack[top] = num;
	printf("stack top[%d] value %d \n", top, num);

}

void pop() {

	top--;
	printf("stack top[%d] value %d \n", top, stack[top]);

}

int stack_full() {
	if (top == 9) {
		printf("stack is full \n");
		return -1;
	}
	else {
		return 0;
	}

}

int  stack_empty() {
	
	if (top == -1) {
		printf("stack is empty \n");
		return -1;
	}

	else {
		return 0;
	}
}

int main() {
	

	!stack_full();
	push(12);
	push(10);
	!stack_empty();
	pop();

	return 0;
}