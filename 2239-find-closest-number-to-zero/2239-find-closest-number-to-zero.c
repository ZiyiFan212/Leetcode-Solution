int findClosestNumber(int* nums, int numsSize) {
    if (numsSize < 1 || numsSize > 1000) return 0;

    int answer = 0;
    int distance = 0;

    if (nums[0] < 0) {
        if (nums[0] == INT_MIN) distance = (-1) * (nums[0] + 1);
        distance = (-1) * nums[0];
        answer = nums[0];
    } else {
        distance = nums[0];
        answer = nums[0];
    }

    if (distance == 0) return 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == 0) {
            return 0;
        } else if (nums[i] > 0) {
            if (nums[i] < distance) {
                distance = nums[i];
                answer = nums[i];
            } else if ((answer < 0) && (nums[i] == ((-1) * answer))) {
                answer = nums[i];
            } else {
                continue;
            }
        } else {
            if ((-1 * nums[i]) < distance) {
                distance = (-1) * nums[i];
                answer = nums[i];
            } else {
                continue;
            }
        }
    }

    //if (answer == -1) return 1;
    return answer;
}