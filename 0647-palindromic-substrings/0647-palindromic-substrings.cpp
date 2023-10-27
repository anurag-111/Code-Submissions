class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() <= 1) {
            return s.size();
        }
        
        int start = 0;
        int count = 0;
        int maxLen = 1;
        for(int i = 0; i < s.size(); i++) {
            // Odd palindrome length
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                count++;
                if(currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;
                right++;
            }
            
            // Even palindrome length
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                count++;
                if(currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;
                right++;
            }
        }
        
        return count;
    }
};