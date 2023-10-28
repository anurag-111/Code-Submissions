class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minValToBuy = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
            if(minValToBuy > prices[i]) {
                minValToBuy = prices[i];
            }
            
            int currentProfit = prices[i] - minValToBuy;
            
            if(currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }
        
        return maxProfit;
    }
};