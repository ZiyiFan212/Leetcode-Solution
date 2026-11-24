class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> s2t;
        std::unordered_map<char, char> t2s;

        const int ls = s.size();
        const int lt = t.size();
        if (ls != lt) return false;

        for (int i = 0; i < ls; i++)  {
            const char cs = s[i];
            const char ct = t[i];

            if (s2t.count(cs) && s2t[cs] != ct) return false;
            if (t2s.count(ct) && t2s[ct] != cs) return false;

            s2t[cs] = ct;
            t2s[ct] = cs;
        } 
        return true;  
    }
};