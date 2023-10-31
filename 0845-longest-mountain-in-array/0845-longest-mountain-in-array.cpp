class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxLen = 0;
        for(int peak = 1; peak < arr.size() - 1; peak++) {
            if(arr[peak] > arr[peak - 1] && arr[peak] > arr[peak + 1]) {
                int left = peak - 1;
                int right = peak + 1;
                
                while(left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                
                while(right < arr.size() - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }
                
                maxLen = max(maxLen, (right - left + 1));
            }
        }
        
        return maxLen;
    }
};