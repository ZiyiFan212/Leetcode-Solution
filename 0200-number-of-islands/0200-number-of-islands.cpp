class Solution {
public:
    int cols;
    int rows;

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid.front().size();

        //vector<vector<int>> countGrid(rows, vector<int>(0));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] != '1') continue;

                dfs(grid, i, j);
                islandCnt++;
            }
        }

       return islandCnt;
    }

private:
    int islandCnt = 0;
    void dfs(vector<vector<char>>& grid, const int row, const int col) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            return;
        }

        if (grid[row][col] != '1') {
            return;
        }

        grid[row][col] = '0';

        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
};