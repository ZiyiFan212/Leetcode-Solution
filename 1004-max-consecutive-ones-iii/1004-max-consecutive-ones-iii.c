int longestOnes(int* nums, int numsSize, int k) {
    if (numsSize < 1) return -1;

    int left = 0;
    int right = 0;
    int answer = 0; 
    int zero_counter = 0;

    while (right < numsSize){
        if (nums[right] == 0) {
            zero_counter++;
        }

        while (zero_counter > k){
            if (nums[left] == 0){
                zero_counter--;
            }
            left++;
        }
        answer = ((right-left+1)>answer) ? (right-left+1) : answer;
        right++;
    }
    
    return answer;
}