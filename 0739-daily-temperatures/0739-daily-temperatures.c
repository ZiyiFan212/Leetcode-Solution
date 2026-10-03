/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    if (temperaturesSize == 0) return NULL;

    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    if (answer == NULL) return NULL;

    for (int i = temperaturesSize - 2; i >= 0; i--) {
        int j = i + 1; 

        while (j < temperaturesSize) {
            if (temperatures[j] > temperatures[i]) {
                answer[i] = j - i;
                break; // jmp out
            } else if (answer[j] == 0) {// right is cooler and no more hot days
                answer[i] = 0; 
                break;
            } else {
                j += answer[j]; 
            }
        }
    }

    return answer;
}