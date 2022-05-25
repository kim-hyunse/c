//#include <stdio.h>
//#include <stdlib.h>
//
//struct NODE {
//    int key;
//    struct NODE next;
//};
//
//int Insertkey(struct NODE* head, NODE* node, int newkey) {
//    struct NODE* ptr = NULL, * pre_ptr = NULL, * old_ptr = NULL;
//    ptr = (struct NODE*)malloc(sizeof(struct NODE));
//    pre_ptr = (struct NODE*)malloc(sizeof(struct NODE));
//    old_ptr = head;
//    ptr = head->next;
//    pre_ptr = ptr->next;
//
//    while (ptr != NULL) {
//        if (pre_ptr == NULL) {
//            node->key = newkey;
//            node->next = NULL;
//            old_ptr->next = node;
//            node->next = ptr;
//            return 0;
//            break;
//        }
//        else if (ptr->key == newkey) {
//            return -1;
//            break;
//        }
//        old_ptr = old_ptr->next;
//        ptr = ptr->next;
//        pre_ptr = pre_ptr->next;
//    }
//}
//
//void ScanList(NODE* head) {
//    struct NODE* ptr, * old_ptr = NULL, * p = head[0].next, * prev = &head[0], * in = NULL;
//    old_ptr = (struct NODE*)malloc(sizeof(struct NODE));
//    ptr = (struct NODE*)malloc(sizeof(struct NODE));
//    ptr = head[0].next;
//    old_ptr = &head[0];
//    in = ptr->next;
//    in = in->next;
//    while (ptr)
//    {
//        if (in == NULL) {
//            in = in->next;
//
//            break;
//        }
//        if (ptr->key < in->key || ptr->key == in->key)
//        {
//            old_ptr = ptr;
//            ptr = ptr->next;
//        }
//        else if (old_ptr->key > in->key)
//        {
//            struct NODE* new_node;
//            while (ptr && old_ptr) {
//                old_ptr = ptr;
//                ptr = ptr->next;
//            }
//            new_node = (struct NODE*)malloc(sizeof(struct NODE));
//            new_node->key = in->key;
//            old_ptr->next = new_node;
//            new_node->next = ptr;
//            in = in->next;
//
//            break;
//        }
//        else {
//            struct NODE* new_node2;
//            new_node2 = ptr;
//            new_node2->next = NULL;
//            new_node2->next = in;
//            in->next = ptr;
//            ptr = ptr->next;
//
//            break;
//        }
//    }
//    if (ptr == NULL) {
//        old_ptr->next = in;
//        in->next = NULL;
//        in = in->next;
//    }
//}
//
//int main() {
//    struct NODE* node;
//    struct NODE* newnode;
//    int newkey[4] = { 250, 300, 50, 500 };
//    node = (struct NODE*)malloc(7 * sizeof(struct NODE));
//    newnode = (struct NODE*)malloc(sizeof(struct NODE));
//    node[0].key = 100;
//    node[0].next = &node[1];
//    node[1].key = 250;
//    node[1].next = &node[2];
//    node[2].key = 467;
//    node[2].next = &node[3];
//    node[3].key = NULL;
//    node[3].next = NULL;
//
//    for (int i = 0; i < 4; i++) {
//        int Key = 0;
//        printf("//---Inserting Key: %d", newkey[i]);
//        Key = Insertkey(&node[0], &node[i + 3], newkey[i]);
//        if (Key == -1) {
//            printf("\nKey already exist.\n");
//        }
//        else if (Key == 0) {
//            printf("\nKey inserted.\n");
//        }
//    }
//    for (int i = 3; i < 8; i++) {
//
//        ScanList(node);
//    }
//    printf("\nTraversing the linked list");
//    for (int i = 0; i < 7; i++) {
//        printf("\nnode[%d] key : %d\n", i, node[i]);
//    }
//    return 0;
//}