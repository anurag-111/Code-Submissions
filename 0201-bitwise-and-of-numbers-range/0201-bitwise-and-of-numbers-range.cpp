// Brute Force :

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int result = left;

//         if (left == 0) {
//             return 0; // Optimization for left == 0
//         }

//         for (int i = left; i <= right; i++) {
//             result = result & i;
//             if (result == 0) {
//                 break; // If result becomes 0, further AND operations won't change the result
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shifts = 0;
        while(left < right) {
            left >>= 1;
            right >>= 1;
            shifts++;
        }
        return left << shifts;
    }
};