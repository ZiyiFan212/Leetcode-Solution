#include <stdio.h>

inline uint64_t hourCounter(const int* piles, const int pilesSize, const uint64_t rate) {
    uint64_t sum_hour = 0;// guard overflow
    for (int i = 0; i < pilesSize; i++) {
        sum_hour += ((uint64_t)piles[i] + rate - 1) / rate;
    }
    return sum_hour;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    if (pilesSize < 1) return -1;

    int left = 1; 
    int right = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }

    while (left <= right) {
        uint64_t middle = left + (right - left) / 2;// left right will not be negative
        
        if (hourCounter(piles, pilesSize, middle) <= h) {
            // shrink to the left
            right = middle - 1;
        } else {
            // too slow
            left = middle + 1;
        }
    }

    return left;
}