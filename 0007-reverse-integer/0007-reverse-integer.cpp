class Solution {
public:
    int reverse(int x) {
        int reverseNum = 0;
        while(x) {
            int digit = x % 10;
            if((reverseNum > INT_MAX / 10) || (reverseNum < INT_MIN / 10)) {
                return 0;
            }
            reverseNum = (reverseNum * 10) + digit;
            x = x / 10;
        }
        return reverseNum;
    }
};

// In the worst case, the while loop iterates for as many times as there are digits in the input integer, which is approximately log10(x).

// The worst-case space complexity of the code remains O(1).