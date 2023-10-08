class Solution {
public:
    bool isAnagram(string s, string t) {
        // Check if the lengths of both strings are not equal,
        // which means they cannot be anagrams.
        if (s.size() != t.size()) {
            return false;
        }
        
        // Create an array to store the frequency of each lowercase letter.
        vector<int> letterFrequency(26, 0);

        // Iterate through both strings simultaneously.
        for (int i = 0; i < s.size(); i++) {
            // Increment the frequency count for the current letter in string s.
            letterFrequency[s[i] - 'a']++;

            // Decrement the frequency count for the current letter in string t.
            letterFrequency[t[i] - 'a']--;
        }
        
        // Check if all frequencies in the array are zero.
        for (int freq : letterFrequency) {
            if (freq != 0) {
                return false; // If not, they are not anagrams.
            }
        }
        
        return true; // If all frequencies are zero, they are anagrams.
    }
};


// TC : O(N)
// SC : O(26) -> O(1)