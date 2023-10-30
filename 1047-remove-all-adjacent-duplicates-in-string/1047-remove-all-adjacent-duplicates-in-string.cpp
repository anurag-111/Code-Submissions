class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> charStack;
        for(char ch : s) {
            if(!charStack.empty() && charStack.top() == ch) {
                // Start to pop
                charStack.pop();
            } else {
                charStack.push(ch);
            }
        }
        
        string result = "";
        while(!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        
        return result;
    }
};