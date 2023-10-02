class Solution {
public:
    string reverseWords(string s) {
        stack<string> wordStack; // Stack to store words
        string reversedString = ""; // The final reversed string
        string currentWord = ""; // Temporary variable to store a word

        for (char ch : s) {
            if (ch == ' ') { // Check for space to separate words
                if (!currentWord.empty()) {
                    wordStack.push(currentWord); // Push the word onto the stack
                }
                currentWord = ""; // Reset the temporary word
            } else {
                currentWord += ch; // Build the current word character by character
            }
        }

        // Add the last word (if any) to the reversed string
        reversedString += currentWord;

        // Reconstruct the reversed string by popping words from the stack
        while (!wordStack.empty()) {
            reversedString = reversedString + ' ' + wordStack.top(); // Append a space and the top word from the stack
            wordStack.pop(); // Pop the word from the stack
        }

        // Remove leading space (if any) from the reversed string
        if (!reversedString.empty() && reversedString[0] == ' ') {
            reversedString = reversedString.substr(1);
        }

        return reversedString; // Return the reversed string
    }
};

// TC : O(N)
// SC : O(N)
