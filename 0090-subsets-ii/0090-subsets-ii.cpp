class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        vector<vector<int>> answer; answer.reserve(2 << numsSize);
        answer.push_back({});
        
        int last_size = 0; 
        for (int i = 0; i < numsSize; ++i) {
            int current_size = answer.size();
            int start = (i > 0 && nums[i] == nums[i - 1]) ? (current_size - last_size) : 0;
            
            last_size = current_size - start;
            for (int j = start; j < current_size; ++j) {
                vector<int> new_subset = answer[j];
                new_subset.push_back(nums[i]);
                answer.push_back(std::move(new_subset));
            }
        }
        return answer;
    }
};