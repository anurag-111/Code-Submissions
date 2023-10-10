class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize commonPrefix with the first string in the vector
        string commonPrefix = strs[0];

        // Iterate through the rest of the strings in the vector
        for (int i = 1; i < strs.size(); i++) {
            string currentString = strs[i];
            int j = 0;

            // Compare characters until a mismatch or the end of one of the strings is reached
            while (j < commonPrefix.size() && j < currentString.size() && commonPrefix[j] == currentString[j]) {
                j++;
            }

            // Update commonPrefix to only include characters up to the mismatch
            commonPrefix = commonPrefix.substr(0, j);

            // If commonPrefix becomes empty, no need to continue
            if (commonPrefix.empty()) {
                return "";
            }
        }

        return commonPrefix;
    }
};
