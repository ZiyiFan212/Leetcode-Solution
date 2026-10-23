char findTheDifference(char* s, char* t) {
    assert(strlen(s) >= 0 && strlen(t) >= 0);

    int result = 0;
    for (int i = 0; i < strlen(s); i++){
        result ^= (int)s[i];
    }
    for (int j = 0; j < strlen(t); j++){
        result ^= (int)t[j];
    }
    return (char)result;
}