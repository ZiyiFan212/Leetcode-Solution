class Solution {
public:
    bool isHappy(int n) {
    std::unordered_set<int> dup;
    dup.insert(n);
    int sum = n;
    while (sum != 1) {
        sum = compute(sum);
        
        if (auto p = dup.insert(sum); p.second == false) {
            return false; // unhappy
        }
    }
    return true;
}

int compute(int sum) {
    std::cout << "\n";
    constexpr int DIVISOR = 10;
    int num = sum;
    int result = 0;

    while (num != 0) {
        int digit = num % DIVISOR;
        //std::cout << digit;
        result += digit*digit;
        num = num / DIVISOR;
    }
    return result;
}
};