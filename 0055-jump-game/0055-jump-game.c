bool canJump(int* nums, int numsSize) {
    if (numsSize < 1) return true;// some boundary check
    if (numsSize == 1 && nums[0] > 0) {
        return true;
    } 
    //if (nums[0] == 0) return false;

    int total_fuel = 0;
    for (int i = 0; i < numsSize; i++){
        if (total_fuel < 0) return false;
        int index_fuel = nums[i];

        if (total_fuel == 0 || total_fuel < index_fuel) {
            total_fuel = index_fuel;
        } 

        total_fuel--;
    }
    return true;
}