class Solution {
    private:
        bool allZero(vector<int> freq) {
            for(int i = 0; i < freq.size(); i++) {
                if(freq[i] != 0) {
                    return false;
                }
            }
            return true;
        }
    public:
        bool checkInclusion(string s1, string s2) {
            vector<int> freq(26, 0);
            if(s1.size() > s2.size()) {
                return false;
            }

            for(int i = 0; i < s1.size(); i++) {
                freq[s1[i] - 'a']++;
                freq[s2[i] - 'a']--;
            }

            if(allZero(freq)) {
                return true;
            }

            // Slide the window over s2 and update the countFreq vector accordingly
            for (int i = s1.size(); i < s2.size(); i++) {
                freq[s2[i] - 'a']--;	// Decrement count for new character in the window
                freq[s2[i - s1.size()] - 'a']++;	// Increment count for character going out of the window

               	// Check if the countFreq vector is all zeros after each window slide
                if (allZero(freq)){
                    return true;
                }
            }

            return false;

        }
};