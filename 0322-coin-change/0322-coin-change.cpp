class Solution {
    private:
        int dp[10010];
        int calculate(vector<int> &coins, int amount) {
            if(amount == 0) {
                return 0;
            }
            
            if(dp[amount] != -1) {
                return dp[amount];
            }
            
            int ans = INT_MAX;
            
            for(int i = 0; i < coins.size(); i++) {
                if(amount - coins[i] >= 0) {
                    ans = min(ans + 0LL, calculate(coins, amount - coins[i]) + 1LL);
                }
            }
            
            dp[amount] = ans;
            return ans;
        }    
    
    public:
        int coinChange(vector<int>& coins, int amount) {
            memset(dp, -1, sizeof(dp));
            int minCoins = calculate(coins, amount);
            
            if(minCoins == INT_MAX) {
                return -1;
            } else {
                return minCoins;
            }
        }
};