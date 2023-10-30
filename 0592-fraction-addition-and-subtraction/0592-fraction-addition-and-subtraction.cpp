class Solution {
public:
    string fractionAddition(string expression) {
        int A = 0, B = 1, a, b;
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
            a = sign * num;

            // Parse the denominator
            if (expression[i] == '/') {
                i++;
                b = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    b = b * 10 + (expression[i] - '0');
                    i++;
                }
            } else {
                b = 1; // If no denominator, assume it's 1
            }

            // Perform the addition
            A = A * b + a * B;
            B *= b;

            // Simplify the fraction
            int g = abs(gcd(A, B));
            A /= g;
            B /= g;
        }

        return to_string(A) + '/' + to_string(B);
    }
};