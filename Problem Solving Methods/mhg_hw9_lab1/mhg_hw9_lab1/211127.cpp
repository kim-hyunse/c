//#include<stdio.h>
//struct NODE {
//	int a;
//	struct NODE* next;
//
//};
//
//void traverse(struct NODE* p) {
//	while (p != NULL) {
//		printf("%d\n", p->a);
//		p = p->next;
//	}
//
//
//}
//
//int main() {
//	struct NODE node[3];
//	node[0].a = 12;
//	node[0].next = &node[1];
//	node[1].a = 12;
//	node[1].next = &node[2];
//	node[2].a = 12;
//	node[2].next = NULL;
//
//
//	traverse(&node[0]);
//	
//	return 0;
//}