#include<iostream>
using namespace std;

#define max 5

class stack {

	int *arr;
	int top;
	public:
		stack(){
			arr = new int[max];
			top = -1;
		}

		int isEmpty(){
			if(this->top == -1){
				return 1;
			}else{
				return 0;
			}
		}

		int isFull(){
			if(this->top == max-1){
				return true;
			}else{
				return false;
			}
		}

		void push(int elem){
			if(this->isFull()){
				cout<<"stack overflow"<<endl;
				return;
			}else{
				this->top++;
				this->arr[this->top] = elem;
			}
		}

		void pop(){
			if(this->isEmpty()){
				cout<<"stack underflow"<<endl;
			}else{
				this->top--;
			}
		}

		int topSize(){
			return this->top;
		}

		int arrayAtTop(int Top){
			this->top = Top;
			return this->arr[Top];
		}

		void display(){
			if(this->top == -1){
				cout<<"stack is empty"<<endl;
			}else{
				for (int i = this->top; i >= 0; i--)
				{
					cout<<this->arr[i]<<endl;
				}
				
			}
		}


};



int main(){

	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	s.push(60); // excced the limit
	cout<<"top will be now : "<<s.topSize()<<endl;
	cout<<"array at : "<<s.arrayAtTop(s.topSize())<<endl;
	s.display();


	return 0;
}