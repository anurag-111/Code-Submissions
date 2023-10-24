class Solution {
    private:
        bool matchFunc(char open, char close) {
            return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
        }
    public:
        bool isValid(string s) {
            stack<char> charStack;
            for(int i = 0; i < s.size(); i++) {
                char ch = s[i];
                if(ch == '(' || ch == '{' || ch == '[') {
                    charStack.push(ch);
                } else {
                    if(charStack.empty() || !matchFunc(charStack.top(), ch)) {
                        return false;
                    }

                    charStack.pop();
                }
            }
            return charStack.empty();
        }
};