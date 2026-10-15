int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    bool is_negative = (dividend >> 31) ^ (divisor >> 31);
    long long longDividend = llabs((long long)dividend);
    long long longDivisor = llabs((long long)divisor);

    long long answer = 0;
     for (int i = 31; i > -1; i--) {
        if ((longDivisor << i) <= longDividend) {
            longDividend -= (longDivisor << i);
            answer += (1LL << i);
        }
    }

    return is_negative ? -answer : answer;
}