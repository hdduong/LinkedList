#include <stdio.h>
#include <stdlib.h>

// REMEMBER to set NULL to the pointer points to deleted node


struct node {
	int data;
	node *next;
};


// idea is that shift next node data 1 by 1
// so with copy data, we do not have to delete the node
void deleteNodeWOHead(node* tobeDeleteNode) {
	node* nextNode = tobeDeleteNode->next;
	node* currentNode = tobeDeleteNode;

	if (nextNode == NULL) { //current node is tail

		free(currentNode);
		return;
	}

	while (nextNode->next != NULL) 
	{
		currentNode->data = nextNode->data;
		currentNode = nextNode;
		nextNode = nextNode->next;
	}

	currentNode->next = NULL;
	
	nextNode->next = NULL;
	free(nextNode);

}

void deleteList(node **head) {
	if (head == NULL)
		return;

	node *current = *head;
	
	while (current != NULL) {
		node* tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = NULL; //This step is IMPORTANT. Otherwise, when free, Pointer is not set to NULL actually. Then when try to print not NULL, shows exception.

}

void printList(node *head) {
	if (head == NULL)
		return;

	node* travel = head;
	while (travel != NULL) {
		printf("%d ",travel->data);
		travel = travel->next;
	}

	printf("\n");
	
}


int main() {
  /*int i = 20;
  int *p = &i;
  f(p);
  printf("i = %d\n", i);*/
  
	node* node1 = (node*)malloc(sizeof(node));
	node1->data = 10;
	node1->next = NULL;

	node* node2 = (node*)malloc(sizeof(node));
	node2->data = 11;
	node2->next = NULL;

	node* node3 = (node*)malloc(sizeof(node));
	node3->data = 12;
	node3->next = NULL;

	node* node4 = (node*)malloc(sizeof(node));
	node4->data = 13;
	node4->next = NULL;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	printList(node1);
	//deleteNodeWOHead(node4);
	deleteList(&node1);
	printList(node1);

	//printf("%d\n ",node1->data);
	free(node1);
  return 0;
}

//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
// 
///* Link list node */
//struct node
//{
//    int data;
//    struct node* next;
//};
// 
///* Given a reference (pointer to pointer) to the head
//    of a list and an int, push a new node on the front
//    of the list. */
//void push(struct node** head_ref, int new_data)
//{
//   /* allocate node */
//   struct node* new_node =
//             (struct node*) malloc(sizeof(struct node));
// 
//   /* put in the data  */
//   new_node->data  = new_data;
// 
//   /* link the old list off the new node */
//   new_node->next = (*head_ref);
// 
//   /* move the head to point to the new node */
//   (*head_ref)    = new_node;
//}
// 
//void printList(struct node *head)
//{
//   struct node *temp = head;
//   while(temp != NULL)
//   {
//      printf("%d  ", temp->data);
//      temp = temp->next;
//   }
//}
// 
//void deleteNode(struct node *node_ptr)   
//{
//   struct node *temp = node_ptr->next;
//   node_ptr->data    = temp->data;
//   node_ptr->next    = temp->next;
//   free(temp);
//}
// 
///* Drier program to test above function*/
//int main()
//{
//    /* Start with the empty list */
//    struct node* head = NULL;
// 
//    /* Use push() to construct below list
//    1->12->1->4->1  */
//    push(&head, 1);
//    push(&head, 4);
//    push(&head, 1);
//    push(&head, 12);
//    push(&head, 1);
// 
//    printf("\n Before deleting \n");
//    printList(head);
// 
//    /* I m deleting the head itself.
//        You can check for more cases */
//    deleteNode(head);
// 
//    printf("\n After deleting \n");
//    printList(head);
//    getchar(); 
//    return 0;
//}
