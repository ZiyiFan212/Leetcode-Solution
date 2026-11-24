class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word)
            words.push_back(word);

        if (words.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            string w = words[i];

            if (p2w.count(p) && p2w[p] != w)
                return false;

            if (w2p.count(w) && w2p[w] != p)
                return false;

            p2w[p] = w;
            w2p[w] = p;
        }

        return true;
    }
};