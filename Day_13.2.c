/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m=matrixSize;
    int n=matrixColSize[0];
    *returnSize=m*n;
    int *result=(int*)malloc(sizeof(int)*(*returnSize));
    int index=0;
    int top=0,bottom=matrixSize-1;
    int left=0,right=matrixColSize[0]-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            result[index++]=matrix[top][i];
        }
        top++;
        for(int j=top;j<=bottom;j++){
            result[index++]=matrix[j][right];
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                result[index++]=matrix[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for(int j=bottom;j>=top;j--){
                result[index++]=matrix[j][left];
            }
            left++;
        }
    }
    return result;
}
