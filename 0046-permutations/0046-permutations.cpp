class Solution {
public:
    vector<vector<int>> answer;
    
    void compute_perm(vector<int> current, vector<int> remaining) {

        if (remaining.empty()) {
            answer.push_back(current);
            return;
        }

        for (int i = 0; i < remaining.size(); i++) {
            vector<int> nextCurrent = current;
            nextCurrent.push_back(remaining[i]);

            vector<int> nextRemaining = remaining;
            nextRemaining.erase(nextRemaining.begin() + i);

            compute_perm(nextCurrent, nextRemaining);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {{}};
        if (nums.size() == 1) return {{nums.at(0)}};

        compute_perm({}, nums);
        return answer;
    }
};