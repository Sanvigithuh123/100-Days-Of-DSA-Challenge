/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value){
    struct node* n=malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    return n;
}

struct node* insertEnd(struct node* head,int value){
    struct node* newNode=createNode(value);
    if(!head){
        newNode->next=newNode;
        return newNode;
    }
    struct node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    
    temp->next=newNode;
    newNode->next=head;
    return head;
}

void Display(struct node* head){
    struct node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

int main() {
    
    struct node* head=NULL;
    int m,value;
    printf("Enter size of list: ");
    scanf("%d",&m);
    printf("Enter elements: ");
    for(int i=0;i<m;i++){
        scanf("%d",&value);
        head=insertEnd(head,value);
    }
    Display(head);

    return 0;
}
