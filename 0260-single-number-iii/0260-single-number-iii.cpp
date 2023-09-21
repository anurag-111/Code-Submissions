/*
Approach 1 : Using maps
TC : O(N)
SC : O(N)
*/

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         vector<int> result;
//         for(int num : nums) {
//             freq[num]++;
//         }

//         for(pair<int, int> pair : freq) {
//             if(pair.second == 1) {
//                 result.push_back(pair.first);
//             }
//         }
//         return result;
//     }
// };

/*
Approach 2 : Using Bit Manipulation
TC : O(N)
SC : O(1)
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: Initialize a variable 'diff' to 0.
        int diff = 0;

        // Step 2: Calculate the XOR of all numbers in 'nums'.
        for(int i = 0; i < nums.size(); i++) {
            diff ^= nums[i];
        }

        // Step 3: Find the rightmost set bit in 'diff'.
        int rightMostSetBit = 1;
        while((diff & rightMostSetBit) == 0) {
            rightMostSetBit <<= 1;
        }

        // Step 4: Initialize a result vector 'result' with two zeros.
        vector<int> result {0, 0};

        // Step 5: Iterate through 'nums' again to separate the two numbers.
        for(int i = 0; i < nums.size(); i++) {
            // Step 6: Check if the rightmost set bit is not set in 'nums[i]'.
            if((nums[i] & rightMostSetBit) == 0) {
                // If not set, XOR 'nums[i]' with the first result.
                result[0] ^= nums[i];
            } else {
                // If set, XOR 'nums[i]' with the second result.
                result[1] ^= nums[i];
            }
        }

        // Step 7: Return the result vector containing the two single numbers.
        return result;
    }
};
