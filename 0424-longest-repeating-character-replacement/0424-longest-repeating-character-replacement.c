int characterReplacement(char* s, int k) {
    if (s == NULL) return 0;
    int length = strlen(s);

    int answer = 0;
    int left = 0; int right = 0;
    int frequency[26] = {0};
    int highest_frequency = 0;
    while (right < length){
        frequency[s[right] - 'A']++;
        if (frequency[s[right] - 'A'] > highest_frequency) highest_frequency = frequency[s[right] - 'A'];


        if ((k + highest_frequency) < (right-left+1)){
            frequency[s[left] - 'A']--;
            left++;
        }

        answer = (answer < (right-left+1)) ? (right-left+1) : answer;
        right++;
    }
    return answer;
}