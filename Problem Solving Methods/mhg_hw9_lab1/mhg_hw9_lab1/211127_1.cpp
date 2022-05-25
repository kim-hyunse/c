#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int key;
	struct NODE* next;
};

void search(struct NODE* p, int search) {
	int count = 0;
	while (p != NULL) {
		if (p->key == search) {
			count++;
			printf("key found\n");
		}
		p = p->next;
	}

	if (count==0) {
		printf("key not found");
	}
	else
	printf("number of key %d", count);
}

int main() {
	
	struct NODE* node;
	node = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE* node2;
	node2 = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE* node3;
	node3 = (struct NODE*)malloc(sizeof(struct NODE));

	if (node == NULL) {
		printf("fail to mollac");
		exit(1);
	}

	node->key = 1;
	node->next = node2;
	node2->key = 2;
	node2->next = node3;
	node3->key = 2;
	node3->next = NULL;

	search(node,4);

	return 0; 
}
