#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *start , *temp , *p;

void insertAtFirst(int ele){
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	if(start == NULL)
		temp->next = NULL;
	else
		temp->next = start;
	
	start = temp;
}

void traversalsll(){
	    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    p = start;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertatlast(int ele){
	   temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

int main(){

	start = NULL;

	insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(30);
    
    printf("Linked List after insertion at the beginning: ");
    traversalsll();


	start = NULL;

	return 0;
}