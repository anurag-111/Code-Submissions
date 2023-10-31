class Solution {
    private:
        bool allZero(vector<int>& count) {
            for (int i = 0; i < 26; i++) {
                if (count[i] != 0) {
                    return false;
                }
            }

            return true;
        }
    
    public:
        bool checkInclusion(string s1, string s2) {
            int len1 = s1.length(), len2 = s2.length();

            if (len1 > len2) {
                return false;
            }

            vector<int> count(26, 0);

            for (int i = 0; i < len1; i++) {
                count[s1[i] - 'a']++;
            }

            for (int i = 0; i < len2; i++) {
                count[s2[i] - 'a']--;

                if (i - len1 >= 0) {
                    count[s2[i - len1] - 'a']++;
                }

                if (allZero(count)) {
                    return true;
                }
            }

            return false;
        }
};