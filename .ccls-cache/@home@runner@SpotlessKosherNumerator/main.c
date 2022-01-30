#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
} typedef node;

node* head;

node* getNewNode(int x) {
	node* newNode = (node*) malloc(sizeof(node));

	newNode->data = x;
	newNode->prev = NULL;
	newNode->prev = NULL;

	return newNode;
}

void deleteList() {
	if(head == NULL) return;
	node* temp = head;
	while(temp != NULL) {
		temp = temp->next;
		free(head);
		head = temp;
	}
}

void filter(int x) {
	if(head == NULL) return;
	node* temp = head;
	node* toDelete = NULL;
	// finds the node to delete
	while(temp->next != NULL) {
		if(temp->data == x){
			toDelete = temp;
			break;
		}
		temp = temp->next;
	}

	if(toDelete != NULL){
		node* prevNode; // Node previous to the one to delete
		node* nextNode; // Node next to the one to delete
		temp = head;
		// Finds prev and next node to the one to delete
		while(temp != NULL){
			if(temp->next == toDelete) {
				prevNode = temp;
			}
			if(temp->prev == toDelete) {
				nextNode = temp;
			}
			temp = temp->next;
		}

		free(toDelete);
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
	}
}

void insertAtHead(int x) {
	node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void insertAtTail(int x) {
	node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	// Goes to the end
	node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}

	newNode->prev = temp;
	temp->next = newNode;
	newNode->next = NULL;
}

void print() {
	node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reversePrint() {
	node* temp = head;
	if(head == NULL) return;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main(void) {
	head = NULL;
	insertAtHead(2); print();
	printf("\n");
	insertAtTail(4); print();
	printf("\n");
	insertAtTail(6); print();
	printf("\n");
	filter(4); print();
	deleteList();
	printf("List deleted\n");
	print();

  return 0;
}