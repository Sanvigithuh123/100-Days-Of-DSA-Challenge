/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include <stdio.h>

int power(int a, int b){
    if(b==0) return 1;
    
    return a*power(a,b-1);
}

int main() {
    
    int p,q;
    
    printf("Enter base integer: ");
    scanf("%d",&p);
    printf("Enter power integer: ");
    scanf("%d",&q);
    
    printf("%d",power(p,q));
    
    return 0;
}
