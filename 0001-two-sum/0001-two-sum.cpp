class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        if (nums.size() == 0) return answer; 
        

        for (int i = 0; i != nums.size(); ++i){
            int num1  = nums.at(i);
            
            for (int j = i + 1; j != nums.size(); ++j) {
                if (num1 + nums.at(j) == target) {
                    answer.emplace_back(i);
                    answer.emplace_back(j);
                    return answer;
                }
               
            }
          
        }

        return answer;
    }
};