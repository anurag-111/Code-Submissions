class Solution {
private:
    bool is_alnum(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    char to_lower(char ch) {
        if((ch >= 'A' && ch <= 'Z')) {
            return ch + 32;
        } else {
            return ch;
        }
    }

public:
    bool isPalindrome(string s) {
        string newString;
        for(int i = 0; i < s.size(); i++) {
            if(is_alnum(s[i])) {
                newString += to_lower(s[i]);
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