bool canConstruct(char* ransomNote, char* magazine) {
    int size_note = strlen(ransomNote);
    int size_maga = strlen(magazine);

    if (size_note < 1) return false;
    if (size_note > size_maga) return false;

    int chart_note[128] = {0};
    for (int i = 0; i < size_note; i++) {
        chart_note[(unsigned char)ransomNote[i]]++;
    }
    int chart_maga[128] = {0};
    for (int j = 0; j < size_maga; j++) {
        chart_maga[(unsigned char)magazine[j]]++;
    }
    for (int k = 0; k < 128; k++){
        if (chart_note[k] > chart_maga[k]) return false;
    }
    return true;
}