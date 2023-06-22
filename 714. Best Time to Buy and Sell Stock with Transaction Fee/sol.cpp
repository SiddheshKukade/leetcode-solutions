class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ///using the concept of effective buy price where we use past profits as buget for buying the next stock.
        int n = prices.size();
        int profit =0;
        int effectiveBuyPrice = prices[0];
        for(int i=1; i<n;i++){
            profit = max(profit, prices[i] - effectiveBuyPrice - fee);
            effectiveBuyPrice = min(effectiveBuyPrice, prices[i] - profit);
        }
        return profit;
    }
};
