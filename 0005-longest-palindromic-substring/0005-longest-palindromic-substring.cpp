class Solution {
public:
    string longestPalindrome(string str) {
        vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
        int length = 0;
        int start = 0;
        for(int gap = 0; gap < str.size(); gap++) {
            for(int i = 0, j = gap; j < str.size(); i++, j++) {
                if(gap == 0) {
                    dp[i][j] = true;
                } else if(gap == 1) {
                    if(str[i] == str[j]) {
                        dp[i][j] = true;
                        start = i;
                    }
                } else {
                    if(str[i] == str[j] && (dp[i + 1][j - 1] == true)) {
                        dp[i][j] = true;
                        start = i;
                    } else {
                        dp[i][j] = false;
                    }
                }
                
                if(dp[i][j] && length < gap + 1) {
                    length = gap + 1;
                }
            }
        }
        
        return str.substr(start, length);
    }
};