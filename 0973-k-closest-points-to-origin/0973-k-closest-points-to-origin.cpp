class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<vector<int>> answer;
        answer.reserve(k);
        std::priority_queue<pair<double, vector<int>>> maxHeap;
       
        for (const vector<int>& point: points) {
            int x = point.at(0);
            int y = point.at(1);
            double distance = std::sqrt(x*x + y*y);

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