/*
 * O(n) solution without using the hash map.
 */

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return {};


        for (int i = 0; i != nums.size(); ++i){
            int num1  = nums.at(i);

            for (int j = i + 1; j != nums.size(); ++j) {
                if (num1 + nums.at(j) == target) {
                    return {i, j};
                }

            }

        }

        return {};
    }
}；
