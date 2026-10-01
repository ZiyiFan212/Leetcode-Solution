class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() < 1) return 0;

        stack<int> sql; 
        for (const string& str : tokens){
            if ((str.compare("+") == 0) || (str.compare("-") == 0)){
                int a = sql.top(); sql.pop();
                int b = sql.top(); sql.pop();
                if (str.compare("+") == 0) sql.push(a + b);
                else sql.push(b - a);
            } else if ((str.compare("*") == 0) || (str.compare("/") == 0)) {
                int a = sql.top(); sql.pop();
                int b = sql.top(); sql.pop();
                if (str.compare("*") == 0) sql.push(a * b);
                else sql.push(b/a);
            } else {
                sql.push(std::stoi(str));
            }
        }
        return sql.top();
    }
};