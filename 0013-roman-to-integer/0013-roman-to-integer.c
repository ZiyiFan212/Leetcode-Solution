int romanToInt(char* s) {
    int map[128] = {0};
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int answer = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (map[s[i]] > map[s[i + 1]]) {
            answer += map[s[i]];
        } else if (map[s[i]] < map[s[i + 1]]) {
            answer += (map[s[i + 1]] - map[s[i]]);
            i = i + 1;
        } else {
            answer += map[s[i]];
        }
    }

    return answer;
}