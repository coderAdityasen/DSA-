#include<iostream>
#include<stack>

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

	void insertatlast(int ele) {

		Node *temp = new Node(ele);

		if(start == nullptr){
			start = temp;
		}else{
			Node* p = start;
        while (p->next != nullptr) {
            p = p->next;
        }
			p->next = temp;
		}

}


	void insertinbtw(int key , int ele){
		if(start == nullptr || start->next == nullptr){
			cout<<"insertion not possible"<<endl;
		}else{
			Node*  p = start;
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
				Node* temp = new Node(ele);
				temp->next = p->next;
				p->next = temp;
			}
		}
	}

	void deletefront(){
		if(start == nullptr){
			cout<<"list is empty"<<endl;
		}else{
			Node* p = start;
			start = start->next;
			delete p;
		}
	}

	void deletelast(){
		if(start == nullptr){
			cout<<"list is empty"<<endl;
			return;
		}else{
			Node* p = start;
			Node* q = nullptr;
			while (p->next != nullptr)
			{
				q = p;
				p = p->next;
			}
			
			if(start == p){
				start = nullptr;
			}else{
				q->next = nullptr;
			}

			delete p;
		}
	}

	void deletebetween( int key){
		if(start == nullptr || start->next == nullptr || start->next->next == nullptr){
			cout<<"list does not have sufficient nodes"<<endl;
		}else{
			Node* p = start;
			Node* q = nullptr;
			while (p!=nullptr)
			{
				if(p->data == key){
					break;
				}else{
					q = p;
					p = p->next;
				}
			}

			if(p == nullptr){
				cout<<"element not found"<<endl;
			}else{
				if(p == start || p->next == nullptr){
					cout<<"elemtn is first or last"<<endl;
				}else{
					q->next = p->next;
					delete p;
				}
			}
			
		}
	}

	void deleteelement(int key){
		
		if(start == nullptr){
			cout<<"list does not have sufficient nodes"<<endl;
		}else{
			Node* p = start;
			Node* q = nullptr;
			while (p!=nullptr)
			{
				if(p->data == key){
					break;
				}else{
					q = p;
					p = p->next;
				}
			}

			if(p == nullptr){
				cout<<"element not found"<<endl;
			}else{
				if(p == start){
					start = start->next;
			        delete p;
					// cout<<"elemtn is first or last"<<endl;
				}else{
					q->next = p->next;
					delete p;
				}
			}
			
		}
	}

	void searchsll(int key){
		if(start == nullptr){
			cout<<"list is empty"<<endl;
		}else{
			Node* p = start;
			while (p != nullptr)
			{
				if(p->data == key){
					break;
				}else{
					p = p->next;
				}
			}

			if(p == nullptr){
			cout<<"not found"<<endl;
		}else{
			cout<<"element found"<<endl;
		}
		}
	}

	void traversal() {
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


	void reverseList(){
		stack<int> st;
		Node* p = start;
		while (p != nullptr)
		{
			st.push(p->data);
			p = p->next;
		}

		while (!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
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

	LinkedList list2;

	list.insertfront(30);
	list.insertfront(20);
	list.insertfront(10);


	list.insertatlast(5);
	list.insertatlast(3);
	list.insertatlast(50);

	list.traversal();

	list.middlenode();


	// list.traversal();

	// list.deleteelement(3);

	// list.traversal();

	// list.reverseList();

  
	return 0;
}