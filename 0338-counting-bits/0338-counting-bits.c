/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    assert(n >= 0);

    int* answer = (int*)calloc((n+1), sizeof(int));
    for (int i = 1; i < (n+1); i++){
       answer[i] = answer[i >> 1] + (i&1);
    }

    *returnSize = n+1;
    return answer;
}