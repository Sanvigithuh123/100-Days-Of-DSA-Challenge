/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
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


void Display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
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
            tail->next=createNode(value);
            tail=tail->next;
        }
    }
    
    Display(head);

    return 0;
}
