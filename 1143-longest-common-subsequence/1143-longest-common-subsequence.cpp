class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<int> lcs(n + 1, 0);
        
        for(int i = 1; i <= m; i++) {
            int prev = 0;
            for(int j = 1; j <= n; j++) {
                int temp = lcs[j];
                if(text1[i - 1] == text2[j - 1]) {
                    lcs[j] = 1 + prev;
                } else {
                    lcs[j] = max(lcs[j], lcs[j - 1]);
                }
                prev = temp;
            }
        }
        
        return lcs[n];
    }
};