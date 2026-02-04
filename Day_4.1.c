/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    
    printf("Enter the size of array: ");
    scanf("%d",&size);
    
    int* arr=(int*)malloc(size*sizeof(int));
    
    for(int i=0;i<size;i++){
        printf("Enter element at %d index: ",i);
        scanf("%d",&arr[i]);
    }
    int temp;
    int left=0,right=size-1;
    while(left<right){
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
