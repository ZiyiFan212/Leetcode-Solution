/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define ROW_SIZE 3
#define MAX_PAIR 17500

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); 
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }

    int answer_size = 0;
    int row_index = 0;// increment when added
    int** answer = (int**)malloc(sizeof(int*) * (MAX_PAIR));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);

    for (int j = 0; j < numsSize; j++){
        int pivot = nums[j];
        if (j > 0 && nums[j] == nums[j-1]) continue;

        int left = j+1; int right = numsSize - 1;
        while (left < right) {
            if (nums[left] + nums[right] == -pivot){
                answer[row_index] = (int*)malloc(sizeof(int)*3);
                answer[row_index][0] = pivot;
                answer[row_index][1] = nums[left];
                answer[row_index][2] = nums[right];
               (*returnColumnSizes)[row_index] = 3;

                row_index++; answer_size++;
                left++; right--;

                while(left < right && nums[left] == nums[left - 1]){
                    left++;
                }
                while(left < right && nums[right] == nums[right + 1]){
                    right--;
                }
                continue;
            }

            if (nums[left] + nums[right] > -pivot){
                right--;
                continue;
            }

            if (nums[left] + nums[right] < -pivot){
                left++;
                continue;
            }
        
        }

    }

    *returnSize = answer_size;
    return answer;
}