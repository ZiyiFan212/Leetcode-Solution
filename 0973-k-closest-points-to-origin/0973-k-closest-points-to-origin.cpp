class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<vector<int>> answer;
        answer.reserve(k);
        std::priority_queue<pair<long long, vector<int>>> maxHeap;
       
        for (const vector<int>& point: points) {
            int x = point.at(0);
            int y = point.at(1);
            long long distance = x*x + y*y;
            
            // add to the queue
            maxHeap.push({distance, point});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            answer.emplace_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return answer;
    }
};