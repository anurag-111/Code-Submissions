class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) {
            return s;
        }
        int maxLen = 1;
        int start = 0;
        for(int i = 0; i < s.size(); i++) {
            // Odd length palindrome
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currLen = right - left + 1;
                if(maxLen < currLen) {
                    maxLen = currLen;
                    start = left;
                }              
                left--;
                right++;
            }
            
            // Even length palindrome
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currLen = right - left + 1;
                if(maxLen < currLen) {
                    maxLen = currLen;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLen);
    }
};

// tc : O(N * N)
// sc : O(1)