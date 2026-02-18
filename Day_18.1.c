/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

int main() {
    
    int n,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number of positions: ");
    scanf("%d",&k);
    
    k=k%n;
    int temp[n],index=0;
    
    for(int i=n-k;i<n;i++){
        temp[index++]=arr[i];
    }
    for(int i=0;i<n-k;i++){
        temp[index++]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
        printf("%d ",arr[i]);
    }

    return 0;
}
