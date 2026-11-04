struct Trie {
    std::array<Trie*, 26> children{};
    std::string word;
};

class Solution {
public:
    int cols = 0;
    int rows = 0;
    std::vector<std::string> matched;

    void dfs(vector<vector<char>>& board, const int row, const int col, Trie* trie) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            return;
        }

        char c = board[row][col];
        if (c == '#') return;

        Trie* next = trie->children[c - 'a'];
        if (!next) return;

        if (!next->word.empty()) {
            matched.push_back(next->word);
            next->word.clear(); 
        }

        board[row][col] = '#';
        dfs(board, row+1, col, next);
        dfs(board, row-1, col, next);
        dfs(board, row, col+1, next);
        dfs(board, row, col-1, next);
        board[row][col] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board.front().size(); 

        Trie* trie = new Trie();
        for (const auto& word : words){
            insert(trie, word);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, trie);
            }
        }
        
        deleteTrie(trie);
        return matched;
    }

    void insert(Trie* root, const string& word_){
        Trie* curr = root;

        for (char c : word_){
            int index = c - 'a';
            if (!curr->children[index]){
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
        }

        curr->word = word_;
    }

    void deleteTrie(Trie* node){
        if (!node) return;
        for (auto child : node->children) {
            deleteTrie(child);
        }
        
        delete node;
    }
};