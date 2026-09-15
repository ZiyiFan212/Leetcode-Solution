// Could just use strlen(), but I decide not too xd
// well this isn't CLEAN code...

char * mergeAlternately(char * word1, char * word2){
    int longest_length = 0;
    int shorter_length = 0;

    int c1 = 0;
    while (*word1 != '\0'){
        c1++;
        word1++;
    }
    word1 = word1 - c1; // !! important
    int c2 = 0;
    while (*word2 != '\0') {
        c2++;
        word2++;
    }
    word2 = word2 - c2;

    longest_length = c1 + c2;// return arr length
    if (c1 == c2) shorter_length = c1; // equal case
    shorter_length = (c1 > c2) ? c2 : c1;// shorter string lenght

    if ((c1 < 1 && c1 > 100) || (c2 < 1 && c2 > 100)) return "";
    char* answer = (char*)malloc((sizeof(char) * longest_length) + 1);

    int word1_index = 0;
    int word2_index = 0;
    for (int i = 0; i < longest_length; i++) {
        // If both strings still have characters left, appending them alternateively (see example)
        if (word1_index < c1 && word2_index < c2) {
            if (i % 2 != 0) {
                answer[i] = word2[word2_index++];
            } else {
                answer[i] = word1[word1_index++];
            }
        } else if (word1_index >= c1) {
            answer[i] = word2[word2_index++];
        } else {
            answer[i] = word1[word1_index++];
        }
    }

    answer[longest_length] = '\0';
    
    return answer;
}