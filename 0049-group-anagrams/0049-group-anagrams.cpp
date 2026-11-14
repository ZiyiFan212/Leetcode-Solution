// Source - https://codereview.stackexchange.com/a/172095
// Posted by Loki Astari
// Retrieved 2026-11-13, License - CC BY-SA 3.0

template<class T, size_t N> 
struct std::hash<std::array<T, N>> {
    auto operator() (const std::array<T, N>& key) const {
        std::hash<T> hasher;
        size_t result = 0;
        for(size_t i = 0; i < N; ++i) {
            result = result * 31 + hasher(key[i]); 
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> ans;

        // construct our hash table, hash value: K and indecies: V
        std::unordered_map<
            std::array<int, 26>, 
            vector<std::string>> map;

        for (const std::string& str: strs) {
            std::array<int, 26> letter{};
            for (const char& c: str) {
                letter[c-'a']++;
            }

            map[letter].emplace_back(str);
        }

        for (auto& [key, value]: map) {
            ans.emplace_back(std::move(value));
        }

        return ans;
    }
};