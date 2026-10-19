class Solution {
public:
    vector<vector<int>> answer;

    void solve(int position, vector<int>& nums){
        if (position == nums.size()){
            answer.push_back(nums);
            return;
        }

        for(int i = position; i < nums.size(); i++){
            swap(nums[position], nums[i]);
            solve(position+1, nums);
            swap(nums[position], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {{}};
        if (nums.size() == 1) return {{nums.at(0)}};

        solve(0, nums);
        return answer;
    }
};