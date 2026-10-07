int search(int* nums, int numsSize, int target) {
    if (numsSize < 1) return -1; // uncessary guard

    int left = 0; int right = numsSize - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (nums[middle] == target){
            return middle;
        } 
        if (nums[left] <= nums[middle]){
            if (target >= nums[left] && target < nums[middle]){
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        } else {
            if (target > nums[middle] && target <= nums[right]){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
    }
    return -1;
}