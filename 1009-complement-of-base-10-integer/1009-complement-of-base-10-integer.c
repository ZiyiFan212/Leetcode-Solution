int bitwiseComplement(int n) {
    int bound = 0;
    for (int i = 31; i >= 0; i--) {
        if ((n >> i) & 1) {
            bound = i;
            break;
        }
    }

    int answer = 0;
    for (int j = 0; j <= bound; j++){
        unsigned int bit = (n >> j) & 1u;
        answer |= ((~bit) & 1u) << j; 
    }
    return answer;

}