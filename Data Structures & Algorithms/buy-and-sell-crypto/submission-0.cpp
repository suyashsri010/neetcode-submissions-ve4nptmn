class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(prices[0]);
        int result = 0;
        for(int i=1;i<prices.size();i++){
            result = max(result,prices[i]-pq.top());
            pq.push(prices[i]);
        }
        return result;
    }
};
