class Solution {
private:
    bool allZero(vector<int> &freq) {
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        
        if(len1 > len2) {
            return false;
        }
        
        vector<int> freq(26, 0);
        for(int i = 0; i < len1; i++) {
            freq[s1[i] - 'a']++;
        }
        
        for(int i = 0; i < len2; i++) {
            freq[s2[i] - 'a']--;
            
            if(i - len1 >= 0) {
                freq[s2[i - len1] - 'a']++;
            }
            
            if(allZero(freq)) {
                return true;
            }
        }
        
        return false;
    }
};