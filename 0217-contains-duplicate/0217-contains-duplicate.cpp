class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int s = nums.size();
        if (s <= 1) return false;
        sort(nums.begin(), nums.end());// we trade time for space
        for (int i = 0; i < s - 1; i++) { 
            if (nums[i] == nums[i + 1]) {
                return true;
            } 
        }
        return false;
    }
};