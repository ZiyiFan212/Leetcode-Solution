/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

// we use qsort
int compare(const void *a, const void *b) {
    int val1 = *(const int*)a;
    int val2 = *(const int*)b;
    
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 1) return NULL;

    

    *returnSize = numsSize;
    int* answer = (int*)malloc(sizeof(int) * numsSize);
    if (!answer) return NULL;

    for (int i = 0; i < numsSize; i++){
        answer[i] = nums[i] * nums[i];
    }
    qsort(answer, numsSize, sizeof(int), compare);
    return answer;
}