class Solution {
    private:
        string seqFunc(string str) {
            char current = str[0];
            int count = 1;
            int length = str.size();
            string result;
            
            for(int i = 1; i < length; i++) {
                if(current != str[i]) {
                    result += to_string(count) + current;
                    current = str[i];
                    count = 1;
                } else {
                    count += 1;
                }
            }
            result += to_string(count) + current;
            return result;
        }
    
    public:
        string countAndSay(int n) {
            string result = "1";        
            if(n == 1) {
                return result;
            }

            for(int i = 2; i <= n; i++) {
                result = seqFunc(result);
            }

            return result;
        }
};

 // nth sequence
 // 1.     1
 // 2.     11
 // 3.     21
 // 4.     1211
 // 5.     111221 
 // 6.     312211
 // 7.     13112221
 // 8.     1113213211
 // 9.     31131211131221
 // 10.    13211311123113112211