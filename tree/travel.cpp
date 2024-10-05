#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node
{
public:
	int data;
	Node *lptr;
	Node *rptr;

	Node(int val)
	{
		data = val;
		lptr = nullptr;
		rptr = nullptr;
	}
};

class Bst
{
private:
	Node *root;

	Node *insert(Node *root, int value)
	{
		if (root == nullptr)
		{
			return new Node(value);
		}

		if (value < root->data)
		{
			root->lptr = insert(root->lptr, value);
		}
		else if (value > root->data)
		{
			root->rptr = insert(root->rptr, value);
		}
		return root;
	}

	void inorder(Node *root)
	{
		if (root == nullptr)
			return;

		inorder(root->lptr);
		cout << root->data << " ";
		inorder(root->rptr);
	}

	void morristraversal(Node *root)
	{
		vector<int> inorder;
		while (root)
		{
			if (root->lptr == nullptr)
			{
				inorder.push_back(root->data);
				root = root->rptr;
			}
			else
			{
				Node *curr = root->lptr;
				while (curr->rptr && curr->rptr != root)
				{
					curr = curr->rptr;
				}

				if (curr->rptr == nullptr)
				{
					curr->rptr = root;
					root = root->lptr;
				}
				else
				{
					curr->rptr = nullptr;
					inorder.push_back(root->data);
					root = root->rptr;
				}
			}
		}

		for (int i : inorder)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	void preordermorries(Node *root)
	{
		vector<int> preorder;
		while (root)
		{

			if (root->lptr == nullptr)
			{
				preorder.push_back(root->data);
				root = root->rptr;
			}
			else
			{
				Node *curr = root->lptr;
				while (curr->rptr && curr->rptr != root)
				{
					curr = curr->rptr;
				}

				if (curr->rptr == nullptr)
				{
					curr->rptr = root;
					preorder.push_back(root->data);
					root = root->lptr;
				}
				else
				{
					curr->rptr = nullptr;
					root = root->rptr;
				}
			}
		}

		for (int i : preorder)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	int height(Node *root, bool &valid)
	{
		if (!root)
			return 0;

		int l = height(root->lptr, valid);
		if (valid)
		{
			int r = height(root->rptr, valid);

			if (abs(l - r) > 1)
			{
				return 0;
			}
			else
			{
				return 1 + max(l, r);
			}
		}
		else
		{
			return -1;
		}
	}

public:
	Bst()
	{
		root = nullptr;
	}

	void insertNode(int data)
	{
		root = insert(root, data);
	}

	void inorder()
	{
		inorder(root);
		cout << endl;
	}

	void morrisInorder()
	{
		morristraversal(root);
	}

	void morrisPreorder()
	{
		preordermorries(root);
	}

	bool checkbalance()
	{
		bool valid = 1;
		height(root, valid);
		return valid;
	}

	void spiraltraverse()
	{
		vector<int> ans;
		stack<Node *> s1, s2;

		s1.push(root);
		while (!s1.empty() || !s2.empty())
		{
			if (!s1.empty())
			{
				while (!s1.empty())
				{
					Node *temp = s1.top();
					s1.pop();
					ans.push_back(temp->data);

					if (temp->rptr)
						s2.push(temp->rptr);
					if (temp->lptr)
						s2.push(temp->lptr);
				}
			}
			else
			{
				while (!s2.empty())
				{
					Node *temp = s2.top();
					s2.pop();
					ans.push_back(temp->data);

					if (temp->lptr)
						s1.push(temp->lptr);
					if (temp->rptr)
						s1.push(temp->rptr);
				}
			}
		}

		for (int i : ans)
		{
			cout << i << " ";
		}
	}

	void bottomview(){
		if(!root) return;

		vector<int> ans;
		queue<Node *> q;

		q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			Node *temp = q.front();
			q.pop();

			for (int i = 0; i < n; i++)
			{
				if(temp->lptr == NULL && temp->rptr == NULL ){
					ans.push_back(temp->data);
				}

				if(temp->lptr){
					q.push(temp->lptr);

					if(temp->rptr){
					q.push(temp->rptr);
				}else{
					ans.push_back(temp->data);
				}
				}else{
					ans.push_back(temp->data);
				}
			}
		}

		for(int i : ans){
			cout << i << " ";
		}
	}
};



int main()
{
	Bst binarytree;

	binarytree.insertNode(20);
	binarytree.insertNode(10);
	binarytree.insertNode(30);
	binarytree.insertNode(11);
	binarytree.insertNode(12);
	binarytree.insertNode(9);

	binarytree.inorder();
	// binarytree.morrisInorder();
	// binarytree.morrisPreorder();
	// binarytree.spiraltraverse();
	binarytree.bottomview();
	// cout<<binarytree.checkbalance() <<" is"<<endl;

	return 0;
}
