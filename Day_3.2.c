int missingNum(int *arr, int size) {
   int sum1=0,sum2=0;
   
   for(int i=0;i<size;i++){
       sum1=sum1+arr[i];
   }
   for(int j=1;j<=size+1;j++){
       sum2=sum2+j;
   }
   return sum2-sum1;
}
