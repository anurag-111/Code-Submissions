// Return type : int
// Func name : maxProfit
// Argument : vector<int> &nums

class Solution {
    public :
        int maxProfit(vector<int> &prices) {
            int maxProfit = 0;
            int minValToBuy = INT_MAX;
            
            for(int i = 0; i < prices.size(); i++) {
                if(minValToBuy > prices[i]) {
                    minValToBuy = prices[i];
                }
                
                int currProfit = prices[i] - minValToBuy;
                
                if(maxProfit < currProfit) {
                    maxProfit = currProfit;
                }
            }
            
            return maxProfit;
        }
};


