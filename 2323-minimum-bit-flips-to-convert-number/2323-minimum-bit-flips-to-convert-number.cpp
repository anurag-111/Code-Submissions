class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int diff = start ^ goal;
        while(diff) {
            count++;
            diff = diff & (diff - 1);
        }
        return count;
    }
};

// Time Complexity (TC): O(log2(max(diff))) where "diff" is the result of XOR between "start" and "goal."
// Space Complexity (SC): O(1), constant space usage regardless of input size.

// Using mask to calculate set bits
// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int diff = start ^ goal;
//         int count = 0;
//         int mask = 1;
//         while(mask <= diff) {
//             if(diff & mask) {
//                 count++;
//             }
//             mask <<= 1;
//         }
//         return count;
//     }
// };

