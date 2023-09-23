class Solution {
public:
    bool isPalindrome(string s) {
        string newString;
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                newString += tolower(s[i]);
            }
        }
        for(char ch : newString) {
            cout << ch;
        }
        
        int i = 0;
        int j = newString.size() - 1;
        while(i < j) {
            if(newString[i] != newString[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};