class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack1, stack2;
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(s[i] == '#') {
                if(!stack1.empty()) {
                    stack1.pop();
                }
            } else {
                stack1.push(ch);
            }
        }
        
        for(int i = 0; i < t.size(); i++) {
            char ch = t[i];
            if(t[i] == '#') {
                if(!stack2.empty()) {
                    stack2.pop();
                }
            } else {
                stack2.push(ch);
            }
        }
        
        if(stack1.size() != stack2.size()) {
            return false;
        }
        
        while(!stack1.empty()) {
            if(stack1.top() != stack2.top()) {
                return false;
            }
            stack1.pop();
            stack2.pop();
        }
        
        return true;
    }
};