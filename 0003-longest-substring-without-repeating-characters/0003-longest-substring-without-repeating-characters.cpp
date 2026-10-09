class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_map<char, int> charMap; 
        charMap.reserve(s.size());

        int left = 0; int max_len = 0; 
        for (int right = 0; right < s.length(); right++) {
            char curr_char = s[right];

            if (charMap.count(curr_char) && charMap[curr_char] >= left) {
               left = charMap[curr_char] + 1; 
            }

            charMap[curr_char] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};