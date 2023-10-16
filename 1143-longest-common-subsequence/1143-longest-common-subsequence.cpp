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

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> lcs(m + 1, vector<int> (n + 1));
        
//         for(int i = 0; i <= m; i++) {
//             for(int j = 0; j <= n; j++) {
//                 if(i == 0 || j == 0) {
//                 lcs[i][j] = 0;
//                 } else if(text1[i - 1] == text2[j - 1]) {
//                     lcs[i][j] = 1 + lcs[i - 1][j - 1];
//                 } else {
//                     lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
//                 }
//             }
//         }
        
//         return lcs[m][n];
        
//     }
// };


// The space complexity is where the significant difference lies:

// Original Code:

// Space complexity: O(m * n)
// It uses a 2D array lcs with dimensions (m+1) x (n+1) to store intermediate results. This results in a space complexity of O(m * n).
// Optimized Code:

// Space complexity: O(min(m, n))
// It uses a 1D array dp with dimensions (n+1) to store intermediate results. The space complexity is determined by the smaller of m and n, making it more memory-efficient.