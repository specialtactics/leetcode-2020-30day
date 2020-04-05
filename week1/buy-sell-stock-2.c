int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    
    // Book profit ahead, decide buy and sell
    for (int i = 0; i < pricesSize; ++i) {
        // If we're at the last price, nothing further we can do (& profit already booked)
        if (i == pricesSize - 1) {
            break;
        }
        
        // If increases, book profits
        if (prices[i] < prices[i+1]) {
            profit += prices[i+1] - prices[i];
        }
    }
    
    return profit;
}

