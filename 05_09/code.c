#include<stdio.h>

#define max 5

void push(int elem);

struct queue
{
	int q[max];
	int f;
	int r;
};


struct queue s;


void insertq(int ele){
	if(s.r == max -1){
		printf("queue is full");
	}else{
		if(s.r == -1 && s.f == -1){
			s.f = 0;
		}
		s.r++;
		s.q[s.r] = ele;
	}
}

void deleteq(){
	if(s.f == -1 && s.r == -1){
		printf("queue us empty");
	}else{
		if(s.f == s.r){
			s.f = s.r = -1;
		}else{
		   s.f++;
		   }
	}
}

void display(){
	if(s.f == -1 && s.r == -1){
		printf("queue us empty");
	}else{
		for (int i = s.f; i <= s.r; i++)
		{
			printf(" %d" , s.q[i]);
		}
		
	}
}




struct cqueue {
	int q[max];
	int f;
	int r;

};

struct cqueue Q;

void insertcq(int ele){
	if(Q.f == 0 && Q.r == max-1){
		printf("\n c queue is full");
	}else{
		if(Q.f == -1 && Q.r == -1){
			Q.f = 0;
		}
		Q.r = (Q.r + 1) % max;
		Q.q[Q.r] = ele;
		}
}

void deletecq(){
	if(Q.f == -1 && Q.r == -1){
		printf("\n c queue is empty");
	}else{
		if(Q.f == Q.r){
			Q.f = Q.r = -1;
		}else{
			Q.f = (Q.f+1) % max;
    		}
	}
}

void displaycq(){
	int i;
	if(Q.f == -1 && Q.r == -1){
		printf("\n c queue is empty");
	}else{
		i = 0;
		while (1)
		{
			printf(" %d" , Q.q[i]);
			if(i == max-1){
				break;
			}else{
			    i = (i+1) % max;	
			}
		}
	}
}

struct dqueue {
	int arr[max];
	int f;
	int r;
};

struct dqueue d;

void insertFront(int elem){
	if(d.f == 0 && d.r == max-1 || d.f == d.r + 1){
		printf("d queue is full");
	}

	if(d.f == -1){
		
	}
}

int main(){

	d.f = -1;
	d.r = -1;

	insertcq(10);
	insertcq(20);
	insertcq(30);
	insertcq(40);
	insertcq(50);

	insertcq(60);

	deletecq();

	insertcq(60);

	printf("\n elemts are : ");
	displaycq();

	return 0;
}
