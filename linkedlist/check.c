#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start , *temp,*p , *q;

void insertatfirst(int ele){
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;

	if(start == NULL){
		temp->next = NULL;
	}else{
		temp->next = start;
	}

	start = temp;

}

void traversal(){
	if(start == NULL){
		printf("list is empty");
	}else{
		p = start;
		int count = 0;
		while (p != NULL)
		{
			printf(" %d \n" , p->data);
			count++;
			p = p->next;
		}
		printf("total elements are : %d\n" , count);
	}
}


void reverseTraversal(struct node *p) {
    if(p == NULL)
        return;

    reverseTraversal(p->next); // First go to the end of the list
    printf("%d \n", p->data);  // Print data on the way back
}

void insertatlast(int ele){
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	if(start == NULL){
		start = temp;
	}else{
		p = start;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
		
	}
}



int main(){

	start = NULL;



	insertatfirst(10);
	insertatfirst(20);
	insertatfirst(30);
	insertatfirst(40);
	insertatfirst(5);

	traversal();

	// reverseTraversal(start);

	return 0;
}