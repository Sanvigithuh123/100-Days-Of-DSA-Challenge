/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff,exp;
    struct node* next;
};

struct node* createNode(int c,int e){
    struct node* n=malloc(sizeof(struct node));
    n->coeff=c;
    n->exp=e;
    n->next=NULL;
    return n;
}

struct node* insertEnd(struct node* head,int c,int e){
    struct node* newNode=createNode(c,e);
    
    if(head==NULL) return newNode;
    
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void Display(struct node* head){
    struct node*temp=head;
    while(temp!=NULL) {
    if(temp->exp==0)
    printf("%d",temp->coeff);
    else if(temp->exp==1)
    printf("%dx",temp->coeff);
    else
    printf("%dx^%d",temp->coeff,temp->exp);
    if(temp->next!=NULL)
    printf(" + ");
    temp=temp->next;
    }
    
}

int main() {
    
    int m;
    printf("Enter size of linked list: ");
    scanf("%d",&m);
    printf("Enter coeff and exp: ");
    struct node* head=NULL;
    for(int i=0;i<m;i++){
        int c,e;
        scanf("%d %d",&c,&e);
        head=insertEnd(head,c,e);
    }
    Display(head);
    
    return 0;
}
