/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


void intersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int arr1[len1], arr2[len2];

    struct Node* temp = head1;
    for(int i = 0; i < len1; i++) {
        arr1[i] = temp->data;
        temp = temp->next;
    }

    temp = head2;
    for(int i = 0; i < len2; i++) {
        arr2[i] = temp->data;
        temp = temp->next;
    }

    int i = len1 - 1;
    int j = len2 - 1;
    int intersectionValue = -1;

    while(i >= 0 && j >= 0) {
        if(arr1[i] == arr2[j]) {
            intersectionValue = arr1[i];
        } else {
            break;
        }
        i--;
        j--;
    }

    if(intersectionValue != -1)
        printf("%d\n", intersectionValue);
    else
        printf("No Intersection\n");
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter size of first list: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    printf("Enter size of second list: ");
    scanf("%d", &m);
    printf("Enter elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    intersection(head1, head2);

    return 0;
}
