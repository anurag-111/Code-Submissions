class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = i;
            for(int j = 1; j * j <= i; j++) {
                int sqr = j * j;
                dp[i] = min(dp[i], dp[i - sqr] + 1);
            }
        }
        
        return dp[n];
    } 
};