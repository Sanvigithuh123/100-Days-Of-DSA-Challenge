/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int key=(count/2)+1;
        temp=head;
        for(int i=1;i<key;i++){
            temp=temp->next;
        }
       
    return temp;
}
