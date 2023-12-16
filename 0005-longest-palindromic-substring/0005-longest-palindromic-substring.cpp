class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) {
            return s;
        }
        
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < s.size(); i++) {
            // For odd length palindrome
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if(currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;
                right++;
            }
            
            // For even length palindrome
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if(currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;
                right++;
            }         
        }
        return s.substr(start, maxLen);
    }
};