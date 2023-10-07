class Solution {
    public:
        string removeOuterParentheses(string s) {
            stack<char> openParenStack;  // Stack to keep track of open parentheses
            string validParentheses = "";     // String to store valid parentheses

            for (int i = 0; i < s.size(); i++) {
                char currentChar = s[i];  // Current character in the input string
                // If s[i] = ( -> check and push
                if (currentChar == '(') {
                    // If it's an opening parenthesis
                    if (!openParenStack.empty()) {
                        // If it's not the outermost opening parenthesis
                        validParentheses += currentChar;  // Add it to the valid parentheses
                    }
                    openParenStack.push(currentChar);  // Push it onto the stack
                } 
                // If s[i] = ) -> Pop and check
                else {
                    // If it's a closing parenthesis
                    openParenStack.pop();  // Remove the corresponding opening parenthesis from the stack

                    if (!openParenStack.empty()) {
                        // If it's not the outermost closing parenthesis
                        validParentheses += currentChar;  // Add it to the valid parentheses
                    }
                }
            }

            return validParentheses;
        }
};

// Time complexity: O(N)
// Space complexity: O(N)
