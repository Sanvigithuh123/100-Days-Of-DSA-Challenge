/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(int value) {
    struct ListNode *n = malloc(sizeof(struct ListNode));
    n->val = value;
    n->next = NULL;
    return n;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head=NULL;
    struct ListNode* current=NULL;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry!=0){
        int sum=carry;
        if(l1!=NULL){
            sum=sum+l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum=sum+l2->val;
            l2=l2->next;
        }
    carry=sum/10;
    struct ListNode* newNode=createNode(sum%10);
    if(head==NULL){
        head=newNode;
        current=newNode;
    }
    else{
        current->next=newNode;
        current=current->next;
    }
    }
    return head;
}
