// Approach 1
// Time Complexity : (log n)
// Space Complexity : O(1)
// Note : In the original approach, the loop continues until mask is greater 
// than or equal to n. The number of iterations is determined by how many times 
// mask needs to be left-shifted before it becomes greater than or equal to n. 
// This can be quite a few iterations, especially for large values of n. 
// For example, if n is 1000, it would take 10 iterations to reach mask = 1024, 
// which is greater than n.

// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         if(n == 0) {
//             return 1;
//         }

//         int mask = 1;
//         while(mask <= n) {
//             n = n ^ mask;
//             mask = mask << 1;
//         }

//         return n;
//     }
// };

/*
5 -> 101
2 -> 010
return 2;

Use XOR operation
*/

// Approach 2
// Time Complexity : (log n)
// Space Complexity : O(1)
//In the improved approach, the loop also continues until mask is greater than 
// or equal to n, but there's no XOR operation inside the loop. Instead, 
// the primary purpose of the loop is to calculate the mask value, and the 
// XOR operation is performed once after the loop. This approach reduces 
// the number of bitwise XOR operations to just one, regardless of the value of n.

class Solution {
public:
    int bitwiseComplement(int n) {
        // Initialize a mask with the lowest bit set to 1.
        int mask = 1;

        // Base case:
        if(n == 0) {
            return 1;
        }
        
        // Calculate the mask by left-shifting until it's greater than or equal to n.
        while (mask <= n) {
            mask = mask << 1;
        }

        // Subtracting 1 from the mask creates a binary mask with all bits set to 1.
        mask = mask - 1;

        // XOR n with the mask to obtain the bitwise complement.
        return n ^ mask;
    }
};


