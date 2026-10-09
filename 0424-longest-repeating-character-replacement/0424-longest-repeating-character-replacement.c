int characterReplacement(char* s, int k) {
    if (s == NULL) return 0;
    int length = strlen(s);

    int answer = 0;
    int left = 0; int right = 0;
    int frequency[26] = {0};
    while (right < length){
        frequency[s[right] - 'A']++;
        int highest_frequency = 0;
        for (int i = 0; i < 26; i++) {
            highest_frequency = (frequency[i] > highest_frequency) ? frequency[i] : highest_frequency;
        }

        if ((k + highest_frequency) < (right-left+1)){
            frequency[s[left] - 'A']--;
            left++;
        }

        answer = (answer < (right-left+1)) ? (right-left+1) : answer;
        right++;
    }
    return answer;
}