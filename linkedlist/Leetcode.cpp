#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;

	Node(int val){
		data = val;
		next = nullptr;
	}
};

class LinkedList{
	private:
	Node* start;

	public:
	LinkedList(){
		start = nullptr;
	}

	void insertfront(int ele){
		Node* n = new Node(ele);
		if(start == nullptr){
			n->next = nullptr;
		}else{
			n->next = start;
		}
		start = n;
	}

	void middlenode(){
	Node *slow = start;
	Node *fast = start;

	while (fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
	}
	

	cout<<slow->data<<" is the middle"<<endl;
}

};

int main(){
	LinkedList list;

	list.insertfront(50);
	list.insertfront(40);
	list.insertfront(30);
	list.insertfront(20);
	list.insertfront(10);

	list.middlenode();

	

	return 0;
}
