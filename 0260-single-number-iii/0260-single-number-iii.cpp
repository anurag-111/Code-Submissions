/*
Approach 1 : Using maps
TC : O(N)
SC : O(N)
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> result;
        for(int num : nums) {
            freq[num]++;
        }

        for(pair<int, int> pair : freq) {
            if(pair.second == 1) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};