class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        if (operations.empty()) return 0;

        int answer = 0;
        vector<int> v;

        for (string& o : operations) {
            if (o == "C") {
                if (!v.empty()) {
                    v.pop_back();
                }
            } else if (o == "D") {
                v.push_back(v.back() * 2);
            } else if (o == "+") {
                int n = v.size();
                if (n >= 2)v.push_back(v.at(n- 1) + v.at(n - 2));
            } else {
                v.push_back(std::stoi(o));
            }
        }

        for (int num : v) answer += num;
        
        return answer;
    }
};
