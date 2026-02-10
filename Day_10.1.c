/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>

int main() {
    
    char s[100];
    
    printf("Enter the string: ");
    fgets(s,sizeof(s),stdin);
    
    
    int len=strlen(s);
    if (s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }
    int left=0,right=len-1;
    
    while(left<right){
        if(s[left]!=s[right]){
            printf("NO");
            return 0;
        }
        left++;
        right--;
    }
    printf("YES");
    
    return 0;
}
