int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    int answer = 1;
    if(numsSize < 1) return 0;

    // sort
    qsort(nums, numsSize, sizeof(int), compare);
    int counter = 1;
    for (int i = 1; i < numsSize; i++){
        if (nums[i] - nums[i-1] == 1){
            counter++;
        } else if (nums[i] == nums[i-1]){
            continue;
        } else {
            counter = 1;
        }
        answer = (counter > answer) ? counter : answer;
    }
    return answer;
}