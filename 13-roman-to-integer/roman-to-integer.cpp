class Solution {
public:
    int romanToInt(string s) {
        // Create a mapping of Roman symbols to their integer values
        unordered_map<char, int> symbolToValue;
        symbolToValue['I'] = 1;
        symbolToValue['V'] = 5;
        symbolToValue['X'] = 10;
        symbolToValue['L'] = 50;
        symbolToValue['C'] = 100;
        symbolToValue['D'] = 500;
        symbolToValue['M'] = 1000;

        int result = 0;

        // Traverse the Roman numeral string
        for (int i = 0; i < s.size(); i++) {
            char currentSymbol = s[i];
            char nextSymbol = (i + 1 < s.size()) ? s[i + 1] : ' '; // Handle the last character
            cout << "next symbol : " << nextSymbol << " ";
            // If the value of the current symbol is less than the value of the next symbol,
            // subtract the current symbol's value from the result, as it represents a subtraction case.
            if (symbolToValue[currentSymbol] < symbolToValue[nextSymbol]) {
                result -= symbolToValue[currentSymbol];
            } else {
                // Otherwise, add the current symbol's value to the result.
                result += symbolToValue[currentSymbol];
            }
        }

        return result;
    }
};


// TC : O(N)
// SC : O(1)