/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

#include <stdio.h>

int main() {
    
    int stack[100];
    int n;
    int top=-1;
    
    printf("Enter the number of operations: ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        int choice;
        printf("Enter choice: ");
        scanf("%d",&choice);
        
        if(choice==1){
            int value;
            scanf("%d",&value);
            if(top<100)
            stack[++top]=value;
        }
        
        else if(choice==2){
            if(top==-1) printf("Stack underflow");
            else printf("%d\n",stack[top--]);
        }
        else if(choice==3){
            if(top!=-1){
                for(int j=top;j>=0;j--){
                    printf("%d ",stack[j]);
                }
                printf("\n");
            }
        }
    }
    

    return 0;
}
