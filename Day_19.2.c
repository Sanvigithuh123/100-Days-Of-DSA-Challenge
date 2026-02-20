int maxSubarraySumCircular(int* nums, int numsSize) {

    int total = nums[0];

    int currMax = nums[0];
    int maxSum = nums[0];

    int currMin = nums[0];
    int minSum = nums[0];

    for (int i = 1; i < numsSize; i++) {

        if (currMax + nums[i] > nums[i]) {
            currMax = currMax + nums[i];
        } 
        else {
            currMax = nums[i];
        }

        if (currMax > maxSum) {
            maxSum = currMax;
        }

        if (currMin + nums[i] < nums[i]) {
            currMin = currMin + nums[i];
        } 
        else {
            currMin = nums[i];
        }

        if (currMin < minSum) {
            minSum = currMin;
        }

        total = total + nums[i];
    }

    if (maxSum < 0) {
        return maxSum;
    }
    else {
        if (maxSum > total - minSum) {
            return maxSum;
        } 
        else {
            return total - minSum;
        }
    }
}
