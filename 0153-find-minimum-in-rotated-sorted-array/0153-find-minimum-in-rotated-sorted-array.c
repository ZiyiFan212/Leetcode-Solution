int findMin(int* nums, int numsSize) {
    if (numsSize < 1) return INT_MIN;

    int left = 0; int right = numsSize - 1;
    while (left < right){
        int middle = left + (right - left)/2;

        if (nums[middle] > nums[right]){
            left = middle + 1;
        } else {// every number is unique
            right = middle;
        }
    }

    return (nums[right] > nums[left]) ? nums[left] : nums[right];
}