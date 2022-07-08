#include <stdio.h>

int stack1[10];
int stack2[10];
int top1 = -1;
int top2 = -1;
//initialize stack 1,2, and top 1,2 

int stack_full() {//check stack is overflow
	if (top1 == 9) {
		printf("stack1 is full \n");
		return 1;
	}
	else {
		return 0;
	}

}



int stack_empty() {//check stack is underflow

	if (top1 == -1) {
		printf("stack1 is empty \n");
		return 1;
	}

	else {
		return 0;
	}
}



void push1(int num) {// in stack1 add value
	
		
	top1++;
	stack1[top1] = num;
	


	

}

void push2(int num) {// in stack2 add value
	
		top2++;
		stack2[top2] = num;
	



}

int pop1() {// in stack1 delete most recent value
		
	top1--;
	
	return stack1[top1+1];

}

int pop2() {// in stack2 delete most recent value

	top2--;

    return stack2[top2+1];
	
}




int main() {
	if (!stack_full()) {//if stack is full, reject insert
		
	push1(10);
	push1(20);
	push1(30);
	push1(40);


	}
	if(!stack_full()&&!stack_empty())
	push2(pop1());
	push2(pop1());
	push2(pop1());//pop from recent one to recent one, so stack1 [3],[2],[1] delete, and insert in stack2 [0],[1],[2] 
	pop1();// only stack1 delete [0]
	push1(pop2());
	push1(pop2());
	push1(pop2());//pop from recent one to recent one, so stack2 [2],[1],[0] delete, and insert in stack2 [0],[1],[2] 

	for (int i = 0; i <= top1; i++) {
		printf("[%d] stack1 value: %d\n", i, stack1[i]);
		
	}



	return 0;
}