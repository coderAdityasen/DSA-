#include<stdio.h>
#include<stdlib.h>


struct Tnode
{
	int data;
	struct Tnode* lptr;
	struct Tnode* rptr;
};

struct Tnode *root,*temp;

void inserttree(int ele , struct Tnode **t){
	if(*t == NULL){
		temp = (struct Tnode*)malloc(sizeof(struct Tnode));
		temp->lptr = temp->rptr = NULL;
		temp->data = ele;
		*t = temp;
	}else{
		if(ele > (*t)->data){
			inserttree(ele , &(*t)->rptr);
		}else if(ele < (*t)->data){
			inserttree(ele , &(*t)->lptr);
		}else{
			printf("dublicate element\n");
		}
	}
}

void inorder(struct Tnode *t){
	if(t != NULL){
		inorder(t->lptr);
		printf("%d " , t->data);
		inorder(t->rptr);
	}
}

void preorder(struct Tnode *root){
	if(root != NULL){
		printf("%d " , root->data);
		preorder(root->lptr);
		preorder(root->rptr);
	}
}

void postorder(struct Tnode *root){
	if(root != NULL){
		postorder(root->lptr);
		postorder(root->rptr);
		printf("%d " , root->data);
	}
}


int main(){

	root = NULL;

    inserttree(10, &root);
    inserttree(8, &root);
    inserttree(12, &root);
    inserttree(4, &root);
    inserttree(9, &root);
    inserttree(15, &root);
    inserttree(5, &root);

	printf("\npreorder: ");
	preorder(root);
	printf("\ninorder : ");
	inorder(root);
	printf("\npostorder: ");
	postorder(root);


	return 0;
}