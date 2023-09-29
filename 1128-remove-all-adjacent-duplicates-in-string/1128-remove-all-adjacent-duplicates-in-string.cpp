class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> charStack;
        string result;
        for(int i = 0; i < s.size(); i++) {
            if(!charStack.empty() && charStack.top() == s[i]) {
                // Duplicate character found
                charStack.pop();
            } else {
                charStack.push(s[i]);
            }
            
        }

        while(!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }
};


// string = abbaca
//          ......
// stack = c -> a  
// newSting = reverse(stack)
