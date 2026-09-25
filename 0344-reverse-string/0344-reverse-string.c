void reverseString(char* s, int sSize) {
    if (sSize < 1) return;

    for (int i = 0; i < sSize / 2; i++) {
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}