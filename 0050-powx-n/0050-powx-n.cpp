class Solution {
public:
    double myPow(double base, int exponent) {
        double result = 1.0;
        int expo = abs(exponent);

        while(expo > 0) {
            if(expo & 1) {
                result *= base;
            }
            base *= base;
            expo = expo >> 1;
        }
        return exponent > 0 ? result : 1 / result;
    }
};