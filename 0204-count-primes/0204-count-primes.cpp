class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n + 1, true);
        int count = 0;
        
        // for 0 and 1 set false
        nums[0] = nums[1] = false;

        for(int i = 2; i < n; i++) {
            if(nums[i]) {
                count++;
                for(int j = 2 * i; j < n; j = j + i) {
                    nums[j] = 0;
                }
            }
        }
        return count;
    }
};

// Time Complexity (TC): The time complexity of this code is O(n * log(log(n))), 
// which is the time complexity of the Sieve of Eratosthenes algorithm.

// Space Complexity (SC): The space complexity is O(n) due to the boolean array nums, 
// which stores whether each number is prime or not.