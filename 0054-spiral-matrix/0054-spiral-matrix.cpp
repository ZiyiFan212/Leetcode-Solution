class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix.front().size();

        vector<int> answer; answer.reserve(m*n);

        int top = 0; int bottom = m - 1;
        int left = 0; int right = n - 1;

        while (top <= bottom && left <= right){
            for (int i = left; i <= right; i++){
                answer.emplace_back(matrix.at(top).at(i));
            }
            top++; 

            if (top > bottom) break;

            for (int j = top; j <= bottom; j++){
                answer.emplace_back(matrix.at(j).at(right));
            }
            right--; // the next horizontal to right should stop before i = n - 2

            if (left > right) break;

            for (int k = right; k >= left; k--){
                 answer.emplace_back(matrix.at(bottom).at(k));
            }
            bottom--;

            if (top > bottom) break; 

            for (int f = bottom; f >= top; f--){
                answer.emplace_back(matrix.at(f).at(left));
            }
            left++;
        }
        return answer;
    }
};