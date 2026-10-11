int hammingWeight(int n) {
    if (n > INT_MAX || n < INT_MIN) exit(1);

    int counter = 0; int i = 0;
    while (i < 32) {
        int bit = (n >> i) & 0x00000001;

        bool isBitSet = bit ^ 1;

        if (!isBitSet) counter++;
        i++;
    }
    return counter;
}