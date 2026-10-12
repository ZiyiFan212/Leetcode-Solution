int missingNumber(int* nums, int numsSize) {
    if (numsSize < 0) return -1;
    int answer = numsSize;
    for (int i = 0; i < numsSize; i++){
        answer ^= i; answer ^= nums[i];
    }
    return answer;
}