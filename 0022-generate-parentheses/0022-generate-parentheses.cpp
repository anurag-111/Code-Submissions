class Solution {
    private:
        vector<string> result;    
        
        void generateStrings(string &str, int open, int close) {
            if(open == 0 && close == 0) {
                result.push_back(str);
                return;
            }
            
            if(open > 0) {
                str.push_back('(');
                generateStrings(str, open - 1, close);
                str.pop_back();
            }
            
            if(close > 0) {
                if(open < close) {
                    str.push_back(')');
                    generateStrings(str, open, close - 1);
                    str.pop_back();
                }
            }
        }
    
    
    public:
        vector<string> generateParenthesis(int n) {
            string str;
            generateStrings(str, n, n);
            return result;
        }
};