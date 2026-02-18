/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *result=(int*)malloc(sizeof(int)*numsSize);
    long long prod=1;
    int count=0;
    int index=-1;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            count++;
            index=i;
        }
        else
        prod=prod*nums[i];
    }
    if(count>1){
        for(int i=0;i<numsSize;i++){
            result[i]=0;
        }
    }
    else if(count==1){
        for(int i=0;i<numsSize;i++){
            result[i]=0;
            result[index]=prod;
        }
    }
    else{
        for(int i=0;i<numsSize;i++){
            result[i]=prod/nums[i];
        }
    }
    *returnSize=numsSize;
    return result;
}
