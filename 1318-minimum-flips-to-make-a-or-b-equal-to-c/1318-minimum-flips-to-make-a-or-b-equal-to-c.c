#define BIT_LENGTH 32
#define MASK 0x00000001
int minFlips(int a, int b, int c){
    int toggle_times = 0;
    for (int i = 0; i < BIT_LENGTH; i++) {
        int abit = (a>>i) & MASK;
        int bbit = (b>>i) & MASK;
        int cbit = (c>>i) & MASK;

        if (cbit) {// when this bit needs to be 1
            if (abit | bbit) continue;// at leas one bit is 1, no toggle
            toggle_times++;//
        } else {// needs to be unset
            // two bits are 1, need to toggle twice
            if (abit & bbit) toggle_times = toggle_times + 2;
            else if (abit | bbit) toggle_times++;
        }
    }
    return toggle_times;
}