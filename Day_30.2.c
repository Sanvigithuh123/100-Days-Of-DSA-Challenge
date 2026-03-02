/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* createNode(int value){
    struct ListNode* n = malloc(sizeof(struct ListNode));
    n->val = value;
    n->next = NULL;
    return n;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int a[100], b[100];  
    int n1 = 0, n2 = 0;

 
    while(l1){
        a[n1++] = l1->val;
        l1 = l1->next;
    }

   
    while(l2){
        b[n2++] = l2->val;
        l2 = l2->next;
    }

    int i = n1 - 1;
    int j = n2 - 1;
    int carry = 0;

    struct ListNode* head = NULL;

    while(i >= 0 || j >= 0 || carry){

        int sum = carry;

        if(i >= 0) sum += a[i--];
        if(j >= 0) sum += b[j--];

        carry = sum / 10;

        struct ListNode* newNode = createNode(sum % 10);
        

        newNode->next = head;
        head = newNode;
    }

    return head;
}
