class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        if (size < 1) return {};

        vector<vector<int>> answer;
        answer.reserve(2 << size); // 2^n is just how many bits are left shifted
        answer.push_back({});

        for (auto number: nums){
            int last = answer.size();

            for (int i = 0; i < last; ++i){
                vector<int> new_subset = answer[i]; 
                new_subset.push_back(number);       
                answer.push_back(new_subset);       
            }
        }
        return answer;
    }
};