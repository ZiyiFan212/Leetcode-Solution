class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //const int strlen = s.size();
        std::stack<std::pair<char, int>> q;// char -> index

        int idx = 0;
        for (const char& c: s) {
            // skip non parenthesis letter
            if (c != '(' && c != ')')  {
                idx++;
                continue;
            }


            // if there are ( in q, pop it out.
            if (c == ')' && !q.empty() && q.top().first == '(') {
                q.pop();
                idx++;
                continue;
            }

            q.push({c, idx});// if no ( or c == '('
            idx++;
        }

        std::string new_str = s;
        while (!q.empty()) {
            const int index = q.top().second;
            new_str.erase(index, 1);
            q.pop();
        }
        return new_str;
    }
};