int singleNumber(int* nums, int numsSize) {
    int seen_once = 0;
    int seen_twice = 0;
    for (int i = 0; i < numsSize; i++){
        seen_once = ~seen_twice & (seen_once ^ nums[i]);
        seen_twice = ~seen_once & (seen_twice ^ nums[i]);
    }
    return seen_once;
}