class Solution {
public:
    vector<vector<int>> ans;
    vector<int> comb;
    int tar = 0;
    int length = 0;

    void backtracking(const int position, const vector<int>& candidates, const int currVal) {
        if (currVal == tar) {
            ans.emplace_back(comb);
            return;
        } 

        for (int i = position; i < length; i++) {
            if (currVal + candidates.at(i) > tar) continue;
            comb.emplace_back(candidates.at(i));
            backtracking(i, candidates, currVal+candidates.at(i));
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tar = target;
        length = candidates.size();
        backtracking(0, candidates, 0);
        return ans;
    }
};