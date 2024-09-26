#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node *prev;

	Node(int val){
		data = val;
		next = nullptr;
		prev = nullptr;
	}
};

class doubleLinkedList {
	private:
	Node *start;
	Node *last;

	public:
	doubleLinkedList(){
		start = nullptr;
		last = nullptr;
	}

	void insertfrontdll(int ele){
		Node *temp = new Node(ele);
		// temp->prev = nullptr;// by default node prev and next is null

		if(start == nullptr){
			// temp->next = nullptr; // by default node prev and next is null
			last = temp;
		}else{
			temp->next = start;
			start->prev = temp;
		}
	start = temp;
	}

	void insertfronbackDll(int ele){
		Node *temp = new Node(ele);

		if(start == nullptr){
			start = temp;
		}else{
			last->next = temp;
			temp->prev = last;
		}

		last = temp;
	}

	void insertinbetween(int key , int ele){
		if(start == nullptr || start->next == nullptr){
			cout<<"list does not contain sufficient node"<<endl;
		}else{
			Node *p = start;
			while (p != nullptr)
			{
				if(p->data == key){
					break;
				}else{
					p = p->next;
				}
			}
			if(p == nullptr){
				cout<<"key not found"<<endl;
			}else{
				if(p->next == nullptr){
					cout<<"last node"<<endl;
				}else{
					Node *temp = new Node(ele);
						temp->next = p->next;
						p->next->prev = temp;
						temp->prev = p;
						p->next = temp;
				}
			}
		}
	}

	void forTraversalDll(){
		if(start == nullptr){
			cout<<"list is empty"<<endl;
		}else{
			Node *p = start;
			while (p!= nullptr)
			{
				cout<<p->data<<" ";
				p = p->next;
			}
			cout<<endl;
			
		}
	}

	void backTraversalDll(){
		if(start == nullptr){
			cout<<"list is empty"<<endl;
		}else{
			Node *p = last;
			while (p!= nullptr)
			{
				cout<<p->data<<" ";
				p = p->prev;
			}
			cout<<endl;
		}
	}
};



int main(){

	doubleLinkedList list;

	list.insertfrontdll(10);
	list.insertfrontdll(20);
	list.insertfrontdll(30);
	list.insertfrontdll(40);
	list.insertfronbackDll(50);
	list.insertinbetween(20 , 25);

	list.forTraversalDll();
	list.backTraversalDll();

	return 0;
}

