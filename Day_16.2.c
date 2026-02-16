void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    int temp[numsSize];
    int index=0;
    for(int i=numsSize-k;i<numsSize;i++){
        temp[index++]=nums[i];
    }
    for(int i=0;i<numsSize-k;i++){
        temp[index++]=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        nums[i]=temp[i];
    }
}
