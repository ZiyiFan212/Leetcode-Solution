#define MASK 0b00000001
int reverseBits(int n) {
    assert(n > -1);

    int answer = 0b00000000;
    for (int i = 0; i < 32; i++){
        int bit = (n >> i) & MASK;
        answer |= (bit << (31 - i));
    }
    return answer;
}