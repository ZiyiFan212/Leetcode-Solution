class Solution {
public:
    bool check(const int (&s1Freq)[26], const int (&s2Freq)[26] ){
        for (int i = 0; i < 26; ++i){
            if (s1Freq[i] != s2Freq[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int s1Length = s1.length();
        int s2Length = s2.length();

        int s1Freq[26] = {0};
        int s2Freq[26] = {0};

        for (int i = 0; i < s1Length; ++i){
            s1Freq[s1[i] - 'a']++;
        }

        // sliding window
        int left = 0; 
        for (int right = 0; right < s2Length; ++right) {
            s2Freq[s2[right] - 'a']++;

            if (right - left + 1 > s1Length) {
                s2Freq[s2[left] - 'a']--;
                left++; // left -> move 1 to the right
            }

            if (right - left + 1 == s1Length) {
                if (check(s1Freq, s2Freq)) return true;
            }
        }


        return false;
    }
};