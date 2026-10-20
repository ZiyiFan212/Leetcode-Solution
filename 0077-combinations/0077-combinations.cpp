class Solution {
public:
    vector<vector<int>> answer;
    vector<int> path;

    void dfs(const int index, const int n, const int k) {
        if (path.size() == k) {
            answer.emplace_back(path);
            return;
        }

        for (int i = index; i <= n - (k - path.size()) + 1; i++) {
            path.emplace_back(i);     
            dfs(i + 1, n, k);       
            path.pop_back();       
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);   
        return answer; 
    }
};