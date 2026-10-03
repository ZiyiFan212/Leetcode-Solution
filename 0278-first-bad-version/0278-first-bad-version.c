// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 0) return -1;

    int left = 1;
    int right = n;
    int middle = left + (right - left)/2;

    while (left < right){
        middle = left + (right - left)/2;
        if (!isBadVersion(middle)){
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}