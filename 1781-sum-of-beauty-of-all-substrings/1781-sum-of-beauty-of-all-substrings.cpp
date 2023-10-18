class Solution {
    private:
        int calcBeauty(vector<int> &mapper) {
            int minCount = INT_MAX;
            int maxCount = INT_MIN;
            for(int i = 0; i < mapper.size(); i++) {
                if(mapper[i] == 0) {
                    continue;
                }
                
                minCount = min(minCount, mapper[i]);
                maxCount = max(maxCount, mapper[i]);                
            }
            
            return maxCount - minCount;
        }
    public :
        int beautySum(string s) {
            int beautySum = 0;
            for(int i = 0; i < s.size(); i++) {
                vector<int> mapper(26, 0);
                for(int j = i; j < s.size(); j++) {
                    // aabcb -> a (s[j]), a(s[j]) -> mapper -> a : 2
                    char letter = s[j] - 'a';
                    mapper[letter]++;
                    beautySum += calcBeauty(mapper);
                }
            }
            return beautySum;
        }
};

// Input: s = "aabcb"
// a, aa, aab, aabc, aabcb, a, ab, abc, abcb..
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Given a string s, return the sum of beauty of all of its substrings.