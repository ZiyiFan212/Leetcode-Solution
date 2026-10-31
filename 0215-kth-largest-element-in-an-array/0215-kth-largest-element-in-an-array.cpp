#include <algorithm>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> maxHeap;
       
        for (const int& num: nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop();
                continue;
            }
        }
        
        return maxHeap.top();
    }
};