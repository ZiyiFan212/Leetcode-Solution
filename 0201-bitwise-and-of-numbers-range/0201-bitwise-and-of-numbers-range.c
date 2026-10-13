int rangeBitwiseAnd(int left, int right) {
    for (int i = 31; i > -1; i--){
        if ((left >> i) == (right >> i)) {
            continue;
        } else {
            return ((0x00000000 | (left >> i)) << i);
        }
    }
    return right;
}