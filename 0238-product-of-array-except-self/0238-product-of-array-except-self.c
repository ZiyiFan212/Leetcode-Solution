/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    if (numsSize > 1000000 || numsSize < 2) return NULL;

    int* answer = (int*) malloc(sizeof(int) * numsSize);

    // calculate left
    int product1 = nums[0];
    for (int i = 0; i < numsSize; i++) {
        
        if (i == 0) {
            answer[i] = 1; // the left value is itself.
        } else {
            answer[i] = product1;
            product1 *= nums[i];
        }
    }

    int product2 = nums[numsSize - 1];
    for (int j = numsSize - 1; j > -1; j--) { // iterate from the back
        if (j == numsSize - 1){
            answer[j] = answer[j] * 1;
        } else {
            answer[j] = answer[j] * product2;
            product2 *= nums[j];
        }
    }

    *returnSize = numsSize;
    return answer;
}