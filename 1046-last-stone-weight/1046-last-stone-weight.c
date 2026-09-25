#define DESTROYED -1

int compare(const void* a, const void* b) {// descending order
   return (*(int*)b - *(int*)a);
}

int lastStoneWeight(int* stones, int stonesSize) {
    if (stonesSize < 1) return 0;
    if (stonesSize == 1) return stones[0];

    qsort(stones, stonesSize, sizeof(int), compare);

    //int size = stonesSize;
    while (stones[0] != DESTROYED) {
        if (stones[1] == DESTROYED) return stones[0];// last stone left

        int result = stones[0] - stones[1];
       
        if (result == 0) {// both destryoed, set it to -1
            stones[0] = DESTROYED; stones[1] = DESTROYED;
        } else {// first one survived, second one destroyed
            stones[0] = result; stones[1] = DESTROYED;
        } 
        qsort(stones, stonesSize, sizeof(int), compare);
    }
    return 0;
}