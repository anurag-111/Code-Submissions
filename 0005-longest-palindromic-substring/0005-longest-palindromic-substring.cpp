class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int start = 0;
        int maxLength = 1;
        
        if(size == 1) {
            return s;
        }
        
        for(int i = 1; i < size; i++) {
            // For odd length palindrome -> Only one center, so no need of checking of the middle element
            // Left -> indicates the left pointer to the current center
			// Right -> indicates the right pointer to the current center
			
			int left = i - 1;
			int right = i + 1;
			while(left >= 0 && right < size && s[left] == s[right]){
                int currentLength = right - left + 1;
                if(currentLength > maxLength) {
                    start = left;
                    maxLength = currentLength;
                }
                left--;
                right++;
            }
            
            // For even length palindrome -> Two centers, so we need to check for both center elements as well.
            // Left pointer -> points to the C1 (center 1)
            // Right pointer -> points to the C2 (center 2)
			left = i - 1;
            right = i;
            while(left >= 0 && right < size && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if(currentLength > maxLength) {
                    start = left;
                    maxLength = currentLength;
                }
                left--;
                right++;
            }            
        }
        
        return s.substr(start, maxLength);
    }
};