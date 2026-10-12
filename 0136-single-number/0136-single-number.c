int singleNumber(int* nums, int numsSize) {
    if (numsSize < 1) return -1;

    if (numsSize == 1) return nums[0];
    int answer = 0;
    for (int i = 0; i < numsSize; i++){
        answer = answer^nums[i]; 
    }
    return answer;
}