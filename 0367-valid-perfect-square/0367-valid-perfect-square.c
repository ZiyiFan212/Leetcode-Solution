bool isPerfectSquare(int num) {
    if (num < 1) return false;

    int increment = 1;
    int result = num - increment;
    for (;;) {
        if (result == 0) return true;
        if (result < 0) return false;

        increment = increment + 2;
        result = result - increment;
    }

    // should neve reach here
    return false;
}