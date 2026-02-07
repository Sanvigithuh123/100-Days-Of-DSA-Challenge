int fib(int n){
  int first=0, second=1,next;

  if(n==0) return 0;

  else{
  for(int i=1;i<n;i++){
    next=first+second;
    first=second;
    second=next;
  }
  return next;
  }
}
