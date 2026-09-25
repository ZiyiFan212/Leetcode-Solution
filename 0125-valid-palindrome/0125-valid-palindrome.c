#include <ctype.h>

bool isPalindrome(char* s) {
    if (strlen(s) < 1) return true;

    int left_index = 0, right_index = strlen(s) - 1;
    while(left_index < right_index) {
        char left = s[left_index];
        char right = s[right_index];
        if (!isalnum(left)) {
            left_index++;
            continue;
        } else if (!isalnum(right)){
            right_index--;
            continue;
        }

        if (tolower(left) != tolower(right)) return false;
        left_index++; right_index--;
    }
    return true;
}