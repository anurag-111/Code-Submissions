class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                charStack.push(ch);
            } 
            else if(charStack.empty()) {
                return false;
            } else {
                 if(ch == ')' && charStack.top() == '(' || ch == '}' && charStack.top() == '{' || ch == ']' && charStack.top() == '[') {
                    // Brackets matched
                     charStack.pop();
                } else {
                    // Brackets not matched 
                    return false;
                 }
            }
        }
        
        return charStack.empty();
    }
};