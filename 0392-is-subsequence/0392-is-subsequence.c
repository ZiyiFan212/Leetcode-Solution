bool isSubsequence(char* s, char* t) {
    if (s == NULL || t == NULL) return false;
    if (*s == '\0' && *t == '\0') return true;// edge case I failed

    while (*t != '\0'){
        if (*s == '\0') return true;

        if (*s == *t){// we do pointer arithmetic here...
            s++;
            t++;
        } else {
            t++;
        }

        if (*s == '\0') return true;
    }

    return false;
}