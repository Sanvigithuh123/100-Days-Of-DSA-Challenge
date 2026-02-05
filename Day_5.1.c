/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>

int main() {
    
    int p,q;
    printf("Enter number of entries in log1: ");
    scanf("%d",&p);
    
    int nums1[p];
    printf("Enter arrival times in server 1: ");
    for(int i=0;i<p;i++){
        scanf("%d",&nums1[i]);
    }
    printf("Enter number of entries in log2: ");
    scanf("%d",&q);
    
    int nums2[q];
    printf("Enter arrival times in server 2: ");
    for(int j=0;j<q;j++){
        scanf("%d",&nums2[j]);
    }
    int res[p+q];
    int i=0,j=0,end=0;

    while(i<p && j<q){
      if(nums1[i]<=nums2[j])
        res[end++]=nums1[i++];
      else
        res[end++]=nums2[j++];
    }
    while(i<p){
      res[end++]=nums1[i++];
    }
    while(j<q){
      res[end++]=nums2[j++];
    }

    for(int k=0;k<p+q;k++){
      printf("%d ",res[k]);
    }

    return 0;
}
