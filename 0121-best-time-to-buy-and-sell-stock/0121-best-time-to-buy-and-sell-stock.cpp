class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, achievedProfit;
        int minimumDayToBuy = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            if(minimumDayToBuy > prices[i]) {
                minimumDayToBuy = prices[i];
            }
            
            int currentProfit = prices[i] - minimumDayToBuy;
            
            if(currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            
            achievedProfit = maxProfit;
        }
        
        return achievedProfit;
    }
};