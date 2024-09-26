#include<stdio.h>

#define max 5

struct stack
{
	int str[max];
	int top;
};

struct stack st;

void push(int elem){
	if(st.top == max-1){
		printf("stack overflow\n");
	}else{
		st.top++;
		st.str[st.top] = elem;
	}
}

void pop(){
	if(st.top == -1){
		printf("stack underflow\n");
	}else{
		st.top--;
	}
}

void display(){
	if(st.top == -1){
		printf("stack is empty\n");
	}else{
		for (int i = st.top; i >= 0; i--)
	{
		printf("%d \n" , st.str[i]);
	}
	}
}

int isempty(){
	if(st.top == -1){
		return 1;
	}else{
		return 0;
	}
}

int isFull(){
	if(st.top == max-1){
		return 1;
	}else{
		return 0;
	}
}

int main(){

	st.top = -1;
	int n,element;

	do
	{
		printf("enter the number 1 for push 2 for pop 3 for display 4 for exit\n");
		scanf("%d" , &n);
		switch (n)
		{
		case 1:
			printf("enter the element\n");
			scanf("%d" , &element);
			push(element);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("thanks for using our program\n");
			break;
		default:
			break;
		}
	} while (n != 4);
	
	return 0;
}


