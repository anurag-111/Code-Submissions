class Solution {
public:
    int myAtoi(string str) {
        // Initialize variables
        int sign = 1;          // Sign of the result, default is positive
        int index = 0;         // Index to track the current character in the string
        int n = str.size();    // Length of the input string
        long long result = 0;  // Accumulator for the resulting integer value

        // Step 1: Skip leading white spaces
        while (index < n && isspace(str[index])) {
            index++;
        }

        // Step 2: Check for a sign (+ or -)
        if (index < n && (str[index] == '-' || str[index] == '+')) {
            sign = (str[index] == '-') ? -1 : 1; // Update the sign, and move to the next character
            index++;
        }

        // Step 3: Read and convert digits
        while (index < n && isdigit(str[index])) {
            // Convert the character into an integer (0 to 9)
            int digit = str[index] - '0';

            // Step 4: Check for integer overflow/underflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN; // Return the maximum or minimum integer value
            }

            // Update the result by multiplying by 10 and adding the digit
            result = result * 10 + digit;

            index++; // Move to the next character
        }

        // Step 5: Return the result, clamped to the 32-bit integer range
        return (result * sign);
    }
};


// Time Complexity : O(N)
// Space Complexity : O(1)