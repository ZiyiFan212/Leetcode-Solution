/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SIZE 26
int comp (int a[], int b[]) {
    for (int i = 0; i < SIZE; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}
void reset (int a[]) {
    for (int i = 0; i < SIZE; i++) {
        a[i] = 0;
    }
}
int* findAnagrams(char* s, char* p, int* returnSize) {
    int orig_map[26] = {0};
    int dup_map[26] = {0};
    int* ans = (int*)malloc(sizeof(int) * 11000);
    int counter = 0;

    const int lenP = strlen(p);
    for (int i = 0; i < lenP; i++) {
        orig_map[p[i] - 'a']++;
    }

    const int lenS = strlen(s);
    int cnt = 0;
    int left = 0, right = 0;
    while (left < lenS && right < lenS) {
        if ((right - left) < lenP) {
            dup_map[s[right] - 'a']++;
            right++;
            if (comp(dup_map, orig_map)) {
                ans[cnt] = 0;
                cnt++;
            }
            continue;
        }

        
        dup_map[s[right] - 'a']++;
        dup_map[s[left] - 'a']--;

        if (comp(dup_map, orig_map)) {
            ans[cnt] = left + 1;
            cnt++;
        } 
        
        right++; left++;
    }


    *returnSize = cnt;
    return ans;
}