class Solution {
public:
    int numDecodings(string s) {
        int current_count = 1;
        int previous_count, two_steps_previous_count;
        int n = s.size();
            
        for(int i = n - 1; i >= 0; i--) {
            int current;
            if(s[i] == '0') {
                current = 0;
            } else {
                current = current_count;
            }
            
            if(i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                current += two_steps_previous_count;
            }
            
            two_steps_previous_count = current_count;
            previous_count = current_count;
            current_count = current;
        }
        
        if(s.empty()) {
            return 0;
        } else {
            return current_count;
        }
    }
};