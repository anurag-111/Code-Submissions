class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreqCount = 0;
        int maxLen = 0;
        int start = 0;
        vector<int> charCount(26, 0);
        
        for(int end = 0; end < s.size(); end++) {
            charCount[s[end] - 'A']++;
            maxFreqCount = max(maxFreqCount, charCount[s[end] - 'A']);
            
            if((end - start + 1) - (maxFreqCount) > k) {
                // Shrink the window
                charCount[s[start] - 'A']--;
                start++;
                
                maxFreqCount = 0;
                for(int i = 0; i < 26; i++) {
                    if(maxFreqCount < charCount[i]) {
                        maxFreqCount = charCount[i];
                    }
                }
                
            }
            
            if((end - start + 1) > maxLen) {
                maxLen = end - start + 1;
            }            
        }
        
        return maxLen;
    }
};