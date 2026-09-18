int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 1) return 0;

    int answer = 0;
    int low_cost = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        low_cost = (prices[i] < low_cost) ? prices[i] : low_cost;

        int curr_profit = prices[i] - low_cost;

        answer = (curr_profit > answer) ? curr_profit : answer;
    }

    return answer;
}