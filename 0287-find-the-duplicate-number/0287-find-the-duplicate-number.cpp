class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++){
            int mod = nums[i] % size;    
            nums[mod] += size;    
        }

        for (int j = 0; j < size; j++) {
            if ((nums[j] / size) >= 2) {
                return j;
            }
        }
        return 0;
    }
};