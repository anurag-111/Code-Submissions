class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int current = 0;
        for(char ch :s) {
            if(ch == '(') {
                current++;
                result = max(result, current);
            } 
            if(ch == ')') {
                current--;
            }
        }
        return result;
    }
};

