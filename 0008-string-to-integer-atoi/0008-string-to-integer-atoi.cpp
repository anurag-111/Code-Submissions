class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int index = 0;
        int n = str.size();
        long long result = 0;
        
        while(index < n && isspace(str[index])) {
            index++;
        }      
        
        if(index < n && (str[index] == '-') || str[index] == '+') {
            sign = (str[index] == '-') ? -1 : 1;
            index++;
        }
        
        while(index < n && isdigit(str[index])) {
            // Convert the character into a integer
            int digit = str[index] - '0';
            if(result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            index++;
        }
        
        return (result * sign);
    }
};