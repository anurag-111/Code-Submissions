class Solution {
public:
    string fractionAddition(string expression) {
        int numeratorSum = 0, denominatorProduct = 1, currentNumerator, currentDenominator;
        size_t i = 0;

        while (i < expression.size()) {
            // Parse the numerator
            int sign = (expression[i] == '-') ? -1 : 1;
            if (expression[i] == '+' || expression[i] == '-') {
                i++;
            }
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            currentNumerator = sign * num;

            // Parse the denominator
            if (expression[i] == '/') {
                i++;
                currentDenominator = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    currentDenominator = currentDenominator * 10 + (expression[i] - '0');
                    i++;
                }
            } else {
                currentDenominator = 1; // If no denominator, assume it's 1
            }

            // Perform the addition
            numeratorSum = numeratorSum * currentDenominator + currentNumerator * denominatorProduct;
            denominatorProduct *= currentDenominator;

            // Simplify the fraction
            int gcdValue = abs(gcd(numeratorSum, denominatorProduct));
            numeratorSum /= gcdValue;
            denominatorProduct /= gcdValue;
        }

        return to_string(numeratorSum) + '/' + to_string(denominatorProduct);
    }
};
