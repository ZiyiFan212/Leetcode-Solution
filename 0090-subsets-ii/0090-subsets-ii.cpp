class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        vector<vector<int>> answer; answer.reserve(2 << numsSize);
        answer.push_back({});
        
        int lastSize = 0; 
        for (int i = 0; i < numsSize; ++i) {
            int currSize = answer.size();
            int start = (i > 0 && nums[i] == nums[i - 1]) ? (currSize - lastSize) : 0;
            
            lastSize = currSize - start;
            for (int j = start; j < currSize; ++j) {
                vector<int> new_subset = answer[j];
                new_subset.push_back(nums[i]);
                answer.push_back(std::move(new_subset));
            }
        }
        return answer;
    }
};