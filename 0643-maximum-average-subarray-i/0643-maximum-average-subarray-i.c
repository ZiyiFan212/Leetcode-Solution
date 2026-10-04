double findMaxAverage(int* nums, int numsSize, int k) {
    int left = 0; int right = k;
    int max_sum = 0;
    for (int j = 0; j < right; j++) max_sum += nums[j];
    int temp_sum = max_sum;
    while (right < numsSize){
        temp_sum = temp_sum + nums[right] - nums[left];

        max_sum = (temp_sum > max_sum) ? temp_sum : max_sum;
        left++; right++;
    }

    return (max_sum/(double)k);
}