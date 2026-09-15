int maxSubArray(int* nums, int numsSize) {
    int max_sum = INT_MIN;
    int curr_sum = 0;
    if (nums == NULL || numsSize < 1) return 0;

    max_sum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        curr_sum += nums[i];

        if (curr_sum > max_sum){
            max_sum = curr_sum;
        }

        if (curr_sum < 0) curr_sum = 0;
    }

    
    return max_sum;
}