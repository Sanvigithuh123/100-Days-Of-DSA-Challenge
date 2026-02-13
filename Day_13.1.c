/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <stdio.h>

int main() {
    
    int m,n;
    printf("Enter the order of matrix: ");
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int r=0;r<m;r++){
        for(int s=0;s<n;s++){
            printf("Enter element at %d,%d: ",r,s);
            scanf("%d",&arr[r][s]);
        }
    }
    int top=0,bottom=m-1;
    int left=0,right=n-1;
    int result[m*n],index=0;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++)
        result[index++]=arr[top][i];
        top++;
        
        for(int j=top;j<=bottom;j++)
        result[index++]=arr[j][right];
        right--;
        
        if(top<=bottom){
            for(int i=right;i>=left;i--)
            result[index++]=arr[bottom][i];
            bottom--;
            
        if(left<=right){
            for(int j=bottom;j>=top;j--)
            result[index++]=arr[j][left];
            left++;
        }
        }
    }
    
    for(int r=0;r<index;r++){
        printf("%d ",result[r]);
    }

    return 0;
}
