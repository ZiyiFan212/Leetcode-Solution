class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() > 20 || nums.size() == 0) return {};
        if (nums.size() == 1) return {std::to_string(nums.at(0))};
        vector<string> answer;

        int startIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int currValue = nums.at(i);
            int prevValue = nums.at(i-1);

            if ((prevValue + 1) == currValue) {
                continue;
            } else {
                string t = "";
                if (startIndex + 1 == i) {
                    t = std::to_string(nums.at(startIndex));
                } else {
                    t += std::to_string(nums.at(startIndex));
                    t += "->";
                    t += std::to_string(prevValue);
                }

                answer.emplace_back(t);
                startIndex = i;
            }
            
        }


        if (startIndex == nums.size() - 1) {
            answer.emplace_back(std::to_string(nums.at(nums.size() - 1)));
            return answer;
        }

        answer.emplace_back(std::to_string(nums.at(startIndex)) + "->" + std::to_string(nums.at(nums.size() - 1)));
        return answer;
    }
};