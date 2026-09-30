class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() < 1) return true;
        
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool grids[9][10] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';// casting
                
                int gridIndex = (i / 3) * 3 + (j / 3);

                // duplicate check: if one returns true, the number is appeared already
                if (rows[i][num] || cols[j][num] || grids[gridIndex][num]) {
                    return false; 
                }

                rows[i][num] = true;
                cols[j][num] = true;
                grids[gridIndex][num] = true;
            }
        }

        return true;
    }
};