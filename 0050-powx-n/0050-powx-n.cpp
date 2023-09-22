class Solution {
public:
    double myPow(double base, int exponent) {
        // Take the absolute value of 'exponent' to work with a positive exponent
        int positiveExponent = abs(exponent);
        
        // Initialize the result to 1.0
        double result = 1.0;
        
        // Loop until 'positiveExponent' becomes 0
        while (positiveExponent > 0) {
            // If the current bit of 'positiveExponent' is 1 (i.e., it's odd), multiply 'result' by 'base'
            if (positiveExponent & 1) {
                result *= base;
            }

            // Halve 'positiveExponent' (equivalent to right-shifting it by 1 bit) and square 'base'
            positiveExponent >>= 1;
            base *= base;
        }
        
        // If the original exponent 'exponent' was negative, take the reciprocal of the result
        return exponent < 0 ? 1 / result : result;
    }
};

/*
Time Complexity (TC): O(log n), where 'n' is the absolute value of the exponent 'exponent'. This code uses binary exponentiation, and the number of iterations in the while loop is proportional to the number of bits in 'positiveExponent,' which is roughly log2(n).

Space Complexity (SC): O(1), which means it uses a constant amount of additional space regardless of the input values 'base' and 'exponent'. The variable names have been made more descriptive, but the space usage remains constant.
*/