/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* createNode(int value){
  struct node*n=malloc(sizeof(struct node));
  n->data=value;
  n->next=NULL;
  n->prev=NULL;
  return n;
}


void Display(struct node* head){
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    
    struct node* head=NULL;
    struct node* tail=NULL;
    int m;
    printf("Enter the size of linked list: ");
    scanf("%d",&m);
    printf("Enter values: ");
    int value;
    for(int i=0;i<m;i++){
        scanf("%d",&value);
        if(head==NULL){
            head=createNode(value);
            tail=head;
        }
        else{
            struct node* newNode=createNode(value);
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    
    Display(head);

    return 0;
}
