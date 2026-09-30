class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        if (m < 1 || n < 1) return;

        // matrix transpon - math115
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) continue; // diagonal -- no switch
                swap(matrix.at(i).at(j), matrix.at(j).at(i));
                
            }
        }

        // switch by columns
        int iniCol = 0;
        int endCol = n - 1;
        while (iniCol < endCol){
            for (int row = 0; row < m; row++){
                swap(matrix.at(row).at(iniCol), matrix.at(row).at(endCol));
            }
            iniCol++; endCol--;
        }
    }
};