/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value){
    struct node* n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

struct node* insertEnd(struct node* head, int value){
    struct node* newNode = createNode(value);

    if(!head){
        newNode->next = newNode; 
        return newNode;
    }

    struct node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

struct node* rotateRight(struct node* head, int k){
    if(!head || head->next == head || k == 0)
        return head;

    int n = 1;
    struct node* temp = head;
    while(temp->next != head){
        temp = temp->next;
        n++;
    }

    k = k % n;
    if(k == 0)
        return head;

    int steps = n - k;
    temp = head;
    for(int i = 0; i < steps; i++){
        temp = temp->next;
    }

    return temp;   
}

void Display(struct node* head){
    if(!head) return;

    struct node* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
}

int main(){
    struct node* head = NULL;
    int n, value, k;
    printf("Enter size of list: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    printf("Enter number of steps: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    Display(head);

    return 0;
}
