class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();

        int per = 0;
        vector<pair<int,int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) continue;

                per += 4;
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    // detect connected box:
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        per--;
                    }
                }
            }
        }

        return per;
    }
};
