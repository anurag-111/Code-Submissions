class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while(left < right) {
            int distance = right - left;
            int minHeight = min(height[left], height[right]);
            int currentArea = distance * minHeight;
            if(currentArea > maxArea) {
                maxArea = currentArea;
            }
            
            if(height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }
        
        return maxArea;
    }
};