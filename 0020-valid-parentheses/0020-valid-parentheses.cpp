class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Create a stack to store opening brackets.
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                // If the current character is an opening bracket, push it onto the stack.
                st.push(s[i]);
            } else {
                // If the current character is a closing bracket, check if it matches the top of the stack.
                if(st.empty() || (st.top() == '(' && s[i] != ')') || (st.top() == '{' && s[i] != '}') || (st.top() == '[' && s[i] != ']')) {
                    return false; // Return false if there is a mismatch or the stack is empty.
                }
                st.pop(); // Pop the matching opening bracket from the stack.
            }
        }

        return st.empty(); // If the stack is empty, all brackets are matched and valid.
    }
};
// Time complexity: O(n), where n is the length of the input string s.
// Space complexity: O(n) due to the stack used to store opening brackets.
