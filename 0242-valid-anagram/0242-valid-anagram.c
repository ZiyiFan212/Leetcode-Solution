bool isAnagram(char* s, char* t) {
    int map[26] = {0};

    const int lenS = strlen(s);
    const int lenT = strlen(t);
    if (lenT != lenS) return false;
    for (int i = 0; i < lenS; i++){
        const char c1 = s[i];
        map[c1 - 'a']++;
    }
    for (int j = 0; j < lenT; j++){
        const char c2 = t[j];
        map[c2 - 'a']--;
        if (map[c2 - 'a'] < 0)return false;
    }
    return true;
}