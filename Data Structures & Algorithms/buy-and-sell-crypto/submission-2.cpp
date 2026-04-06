class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum_upto_today = prices[0];
        int maxi_profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>minimum_upto_today) maxi_profit = max(maxi_profit,prices[i]-minimum_upto_today);
            else minimum_upto_today = min(prices[i],minimum_upto_today);
        }
        return maxi_profit;
    }
};
