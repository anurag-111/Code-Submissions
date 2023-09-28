class Solution {
private:
    bool is_alnum(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        } else {
            return false;
        }
    }

    char to_lower(char ch) {
        if(ch >='A' && ch <= 'Z') {
            return ch + 32;
        } else {
            return ch;
        }
    }

public:
    bool isPalindrome(string s) {
        string str;
        for(int i = 0; i < s.size(); i++) {
            if(is_alnum(s[i])) {
                str += to_lower(s[i]);
            }
        }

        for(char ch : str) {
            cout << ch;
        }

        int i = 0;
        int j = str.size() - 1;
        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};