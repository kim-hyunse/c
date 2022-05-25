#include <stdio.h>
#define MAX_STACK_SIZE 10


struct STACK {

	int stack [MAX_STACK_SIZE];
	int top;

} stack = { {0,},-1 };

bool stack_full() {
	
	return stack.top >= MAX_STACK_SIZE - 1;
}




void push(const int val){//appends data 

	if (stack_full()) {

		printf("push():stack is full\n");
		
	}
		stack.top++;
		stack.stack[stack.top] = val;
		printf("push [%d]: %d\n", stack.top, val);


}

bool stack_empty() {

	return stack.top < 0;
}

int pop() {//remove recent data 
	if (stack_empty()) {
		printf("push():stack is empty\n");
		return 0;
	}
	int val = stack.stack[stack.top];
	printf("pop [%d]: %d\n", stack.top, val);
	stack.top--;
	return 0; //top data
}




int main() {

	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	pop(); //pop100
	pop(); //pop200
	pop();
	push(100);
	push(200);
	push(300);








	return 0;
}