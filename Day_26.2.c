


typedef struct MyLinkedList {
    int data;
    struct MyLinkedList* next;
} MyLinkedList;

/* Create linked list (with dummy head) */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* dummy = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    dummy->next = NULL;
    return dummy;
}

/* Get value at index */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* temp = obj->next;  
    int i = 0;

    while (temp != NULL) {
        if (i == index)
            return temp->data;
        temp = temp->next;
        i++;
    }
    return -1;
}

/* Add at head */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->data = val;
    newNode->next = obj->next;
    obj->next = newNode;
}

/* Add at tail */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->data = val;
    newNode->next = NULL;

    MyLinkedList* temp = obj;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Add at index */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* temp = obj;
    int i = 0;

    while (temp->next != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    if (i != index)
        return;  // index > length

    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete at index */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* temp = obj;
    int i = 0;

    while (temp->next != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
        return;

    MyLinkedList* del = temp->next;
    temp->next = del->next;
    free(del);
}

/* Free entire list */
void myLinkedListFree(MyLinkedList* obj) {
    while (obj != NULL) {
        MyLinkedList* temp = obj;
        obj = obj->next;
        free(temp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
