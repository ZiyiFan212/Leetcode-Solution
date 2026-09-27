class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 1) return {{0, 0}};

        vector<vector<int>> answer; answer.reserve(intervals.size());

        std::sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a.front() < b.front();
            });

        int currMin = intervals.front().front(); 
        int currMax = intervals.front().back();
        
        for (int i = 1; i < intervals.size(); i++) {
            const vector<int>& smallIntervals = intervals[i];
            int val1 = smallIntervals.front();
            int val2 = smallIntervals.back();

            if (val1 > currMax){
                answer.push_back({currMin, currMax});
                currMin = val1; currMax = val2;
                continue;
            }

            if (val1 == currMax){
                currMax = val2;
                continue;
            }

            if (val1 < currMax) {
                currMax = (currMax < val2) ? val2 : currMax;
                currMin = (currMin < val1) ? currMin : val1;
            }
        }
        // emplace the last one
        answer.push_back({currMin, currMax});
        return answer;
    }
};