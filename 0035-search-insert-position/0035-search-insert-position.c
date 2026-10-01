int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize < 1) return -1;

    int left = 0;
    int right = numsSize -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target){
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    for (int i = 1; i < numsSize; i++){
        int prev_index = i - 1;
        int curr_index = i;
        if (nums[prev_index] < target && target < nums[curr_index]) {
            return curr_index;
        } 
    }

    if (target < nums[0]) return 0;
    return numsSize;
}