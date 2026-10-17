class Solution {
public:
    vector<string> answer; 
    
    bool isValid(const string& s){
        int balance = 0;
        for (char c : s){
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
            }
            if (balance < 0) return false;
            
        }
        return balance == 0;
    }

    void dfs(string s, const int leftInvalid, const int rightInvalid, const int position) {

       if (leftInvalid == 0 && rightInvalid == 0) {
            if (isValid(s)) {
                answer.emplace_back(s);
            } 
            return;
        }

        for (int i = position; i < s.size(); i++){
            if (i > position && s[i] == s[i-1]) continue;

            string edited;
            if (s[i] == '(' && leftInvalid > 0) {
                edited = s.substr(0, i) + s.substr(i+1);
                dfs(edited, leftInvalid-1, rightInvalid, i);
            } else if (s[i] == ')' && rightInvalid > 0) {
                edited = s.substr(0, i) + s.substr(i+1);
                dfs(edited, leftInvalid, rightInvalid-1, i);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int strLength = s.length();
        if (strLength < 1) return {};

        // find invalid parentheses
        int leftInvalid = 0, rightInvalid = 0;
        for (const char c : s) {
            if (c == '(') {
                leftInvalid++;
            } else if (c == ')') {
                if (leftInvalid > 0) leftInvalid--;
                else rightInvalid++;
            }
        }

        if (rightInvalid == 0 && leftInvalid == 0) return {s};

        // dfs algo, prunning the branches as well
        dfs(s, leftInvalid, rightInvalid, 0);

        return answer;
    }
};