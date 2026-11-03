class Solution {
public:
    std::string target;
    int rows = 0;
    int cols = 0;

    bool dfs(
        vector<vector<char>>& board, int r, int c, int index,    vector<vector<bool>>& visited) {
            if (r < 0 || r >= rows || c < 0 || c >= cols) return false;

            if (visited[r][c] == true) return false;

            if (board[r][c] != target[index]) return false;

            if (index == target.size()-1) return true;

            visited[r][c] = true;
            bool found =
                dfs(board, r-1, c, index+1, visited) ||
                dfs(board, r+1, c, index+1, visited) ||
                dfs(board, r, c-1, index+1, visited) ||
                dfs(board, r, c+1, index+1, visited);

            visited[r][c] = false;
            return found;
        }

    bool exist(vector<vector<char>>& board, string word) {
        target = word;

        rows = board.size();
        cols = board.front().size();
        std::vector<std::vector<bool>> visitGrid(rows, std::vector<bool>(cols, false));
       
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, i, j, 0, visitGrid)) return true;
            }
        } 

        return false;
    }
};