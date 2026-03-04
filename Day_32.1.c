/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>

int main() {
    
    int n;
    printf("Enter size of stack: ");
    scanf("%d",&n);
    int stack[n];
    int top=-1;
    printf("Enter stack elements to push: ");
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        stack[++top]=val;
    }
    int pop;
    printf("Enter the number of pop operations: ");
    scanf("%d",&pop);
    for(int i=0;i<pop;i++){
        if(top!=-1)
        top--;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }

    return 0;
}
