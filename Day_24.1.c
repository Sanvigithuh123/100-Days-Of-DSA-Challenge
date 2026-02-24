/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
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

struct node* removeElement(struct node* head,int data){
    while(head!=NULL && head->data==data){
        struct node* temp=head;
        head=head->next;
        free(temp);
    }
    struct node* current=head;
    while(current!=NULL && current->next!=NULL){
        if(current->next->data==data){
            struct node* temp=current->next;
            current->next=current->next->next;
            free(temp);
        }
        current=current->next;
    }
    return head;
}

void Display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main() {
    
    struct node* head=NULL;
    struct node* tail=NULL;
    
    int m;
    printf("Enter the size of linked list: ");
    scanf("%d",&m);
    printf("Enter elements: ");
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
    int data;
    printf("Enter the key to remove: ");
    scanf("%d",&data);
    head=removeElement(head,data);
    Display(head);

    return 0;
}
