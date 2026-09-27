int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    if (numbersSize < 2 || numbers == NULL) {
        *returnSize = 0;
        return answer;
    }

    int left = 0;
    int right = numbersSize - 1;

    while (left < right) {
        long long sum = (long long)numbers[left] + (long long)numbers[right];

        if (sum == target) {
            answer[0] = left + 1;
            answer[1] = right + 1;
            *returnSize = 2;
            return answer;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;
    return answer;
}
