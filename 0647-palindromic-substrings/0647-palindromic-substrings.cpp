class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        if(s.size() == 1) {
            return 1;
        }
        
        for(int i = 0;  i < s.size(); i++) {
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};