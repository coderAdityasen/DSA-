#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front, *rear, *temp;

void insertinqueue(int ele) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void deleteinqueu() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *p = front;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {

	front = NULL;
	rear = NULL;
    int key, n;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element into queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch (key) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &n);
                insertinqueue(n);
                break;

            case 2:
                deleteinqueu();
                break;

            case 3:
                printf("Queue: ");
                displayQueue();
                break;

            case 4:
                printf("Thanks for using the queue program!\n");
                break;

            default:
                printf("Please enter a valid key value.\n");
                break;
        }
    } while (key != 4);

    return 0;
}
