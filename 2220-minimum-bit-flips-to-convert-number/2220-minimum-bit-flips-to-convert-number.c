#define MASK 0x00000001
int minBitFlips(int start, int goal) {
    assert(start >= 0 && goal >= 0);

    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (((start >> i) & MASK) != ((goal >> i) & MASK)) cnt++;
    }
    return cnt;
}