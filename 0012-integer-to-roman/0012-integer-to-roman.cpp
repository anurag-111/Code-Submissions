class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result;
        
        for(int i = 0; i < value.size(); i++) {
            while(num >= value[i]) {
                result += symbol[i];
                num -= value[i];
            }
        }
        
        return result;      
    }
};

// Time complexity : O(13) -> O(1)
// Space complexity : O(13) -> O(1)