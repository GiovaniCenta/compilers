#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int key;
	struct Node* next;
};

void push(struct Node** head_ref, int new_key);
bool search(struct Node* head, int x);
void printList(struct Node* n);