class Solution {
public:
    int myAtoi(string s) {
        int index = 0, sign = 1;
        long long result = 0;
        const int n = s.size();

        while (index < n && isspace(s[index])) {
            index++;
        }

        if (index < n && (s[index] == '-' || s[index] == '+')) {
            sign = (s[index++] == '-') ? -1 : 1;
        }

        while (index < n && isdigit(s[index])) {
            result = result * 10 + (s[index++] - '0');

            if (result * sign > INT_MAX) {
                return INT_MAX;
            }

            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return static_cast<int>(result * sign);
    }
};
