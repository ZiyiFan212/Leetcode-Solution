#define TOTAL_BITS 32
int hammingWeight(int n) {
    if (n > INT_MAX || n < INT_MIN) exit(1);

    int counter = 0;
    int mask = 0x00000001;
    for (int i = 0; i < TOTAL_BITS; i++) {
        bool isBitSet = ((n >> i) & mask) ^ mask;
        if (!isBitSet) counter++;
    }
    return counter;
}