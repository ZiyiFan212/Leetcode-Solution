class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() < 0) return -1;//guard
        int arrayLength = nums.size();

        int left = 0 ,right = 0;
        int sum = 0;
        int length = INT_MAX; 

        
        // sliding window
        while (right < arrayLength) {
            sum += nums.at(right);

            while (sum >= target) {
                length = min(length, (right-left+1));
                sum -= nums.at(left);
                left++;
            }

            
            right++;
        }
        return length == INT_MAX ? 0 :length;
    }
};