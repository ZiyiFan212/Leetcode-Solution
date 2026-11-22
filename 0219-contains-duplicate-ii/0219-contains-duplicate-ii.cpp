// Hashmap to find dup
// return abs(i - j)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> m;

        const int len = nums.size();
        for (int i = 0; i < len; i++) {
            const int v = nums.at(i);
            if (m.contains(v)) {
                const int diff = std::abs(i - m[v]);
                if (diff <= k) {
                    return true;
                }
            }
            m[v] = i;
        }
        return false;
    }
};