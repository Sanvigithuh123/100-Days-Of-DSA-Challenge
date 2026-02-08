bool isPowerOfTwo(int n) {
    
    if(n<=0) return 0;
    if(n==1) return 1;
    long long prod=1;
    for(int i=1;prod<n;i++) {
        prod=prod*2;
    
    }
    if(prod==n) return 1;
    else return 0;   
}
