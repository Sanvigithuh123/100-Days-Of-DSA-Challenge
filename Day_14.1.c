/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>

int main() {
    
    int n;
    
    printf("Enter the size of matrix: ");
    scanf("%d",&n);
    
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter element at %d,%d: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    int value1=0,value2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j && arr[i][j]==1)
            value1=1;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && arr[i][j]==0)
            value2=1;
        }
    }
    
    if(value1 && value2==1)
    printf("Identity Matrix");
    else
    printf("Not an Identity Matrix");

    return 0;
}
