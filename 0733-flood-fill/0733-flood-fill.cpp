class Solution {
public:
    int max_row = 0;
    int max_col = 0;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        max_row = image.size();
        max_col = image.front().size();
        dfs(image, image[sr][sc], sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, const int starting_color, const int r, const int c, const int color) {

        if (r < 0 || r >= max_row || c < 0 || c >= max_col) {
            return;
        }

        if (image[r][c] != starting_color) {
            return;
        } else {
            image[r][c] = color;
        }

        // Four directions
        dfs(image, starting_color, r+1, c, color);
        dfs(image, starting_color, r, c+1, color);
        dfs(image, starting_color, r-1, c, color);
        dfs(image, starting_color, r, c-1, color);
    }
};