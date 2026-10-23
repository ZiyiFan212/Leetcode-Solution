int findPermutationDifference(char* s, char* t) {
    
    int abs = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char sc = s[i];
        for (int j = 0; t[j] != '\0'; j++) {
            if ((sc - 'a') == (t[j] - 'a')) {
                abs += (j-i<0) ? ((-1)*(j-i)) : (j-i);
            }
        }
    }
    return abs;
}