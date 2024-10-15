#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int val)
	{
		data = val;
		next = nullptr;
	}
};

class LinkedList
{
private:
	Node *start;
	Node *last;

public:
	LinkedList()
	{
		start = nullptr;
		last = nullptr;
	}

	void insertfront(int ele)
	{
		Node *n = new Node(ele);
		if (start == nullptr)
		{
			n->next = nullptr;
		}
		else
		{
			n->next = start;
		}
		start = n;
	}

	void deleteelement(int key){
		if(start == nullptr){
			cout<<"list does not have sufficient nodes"<<endl;
		}else{
			Node* p = start;
			Node* q = nullptr;
			while (true)
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

	void deleteinalternate(){
		Node *p = start;
		Node *q = nullptr;

	}

	// curcular insertion in linked list

	void insertInCicularList(int ele)
	{
		Node *temp = new Node(ele);
		if (start == NULL)
		{
			start = temp;
		}
		else
		{
			Node *p = start;
			while (p->next != start)
			{
				p = p->next;
			}
			p->next = temp;
		}
		last = temp;
		temp->next = start;
	}

	void traversal()
	{
		if (start == nullptr)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			Node *p = start;

			while (true)
			{
				cout << p->data << " ";
				p = p->next;

				if (p == start) break;
			}
			cout << endl;
		}
	}

	void josephtraverse(int k)
	{
		if (start == nullptr)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			Node *p = start;
			int count = 0;
			while (p->next != p)
			{
				count++;
				if(count == k){
					Node *temp = p;
					p=p->next;
					deleteelement(temp->data);
					count = 0;
				}else{
					p = p->next;
				}
			}
			
		cout << p->data<< endl;
		}
	}

	void middlenode()
	{
		Node *slow = start;
		Node *fast = start;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		cout << slow->data << " is the middle" << endl;
	}
};

int main()
{
	LinkedList list;

	list.insertInCicularList(10);
	list.insertInCicularList(20);
	list.insertInCicularList(30);
	list.insertInCicularList(40);
	list.insertInCicularList(50);
	list.insertInCicularList(60);
	list.insertInCicularList(70);

	list.traversal();
	list.josephtraverse(2);

	// list.insertfront(50);
	// list.insertfront(40);
	// list.insertfront(30);
	// list.insertfront(20);
	// list.insertfront(10);

	// list.middlenode();

	return 0;
}
