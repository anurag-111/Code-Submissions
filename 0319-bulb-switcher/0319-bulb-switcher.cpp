class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        
        int left = 1;
        int right = n;
        int result = 0;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid <= n / mid) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};