class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& it : frequencyMap) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop(); 
            }
        }

        vector<int> answer;
        answer.reserve(k);
        while (!minHeap.empty()) {
            answer.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return answer;
    }
};