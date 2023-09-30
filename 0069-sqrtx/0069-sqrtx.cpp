class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }

        int result = 0;
        int start = 1;
        int end = x;

        while(start <= end) {
            int mid = (start + (end - start) / 2);
            if(mid <= x / mid) {
                start = mid + 1;
                result = mid;
            } else {
                end = mid - 1;
            }
        }

        return result;
    }
};