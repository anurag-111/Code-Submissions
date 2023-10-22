class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Target found
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicate elements by narrowing the search range
            while (low < mid && nums[low] == nums[mid]) {
                low++;
            }
            
            // Check which sub-array is sorted
            if (nums[low] <= nums[mid]) {  // Left sub-array is sorted
                // Check if the left sub-array contains the target
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;  // Search in the left sub-array
                } else {
                    low = mid + 1;  // Search in the right sub-array
                }
            } else { // Right sub-array is sorted
                // Check if the right sub-array contains the target
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Search in the right sub-array
                } else {
                    high = mid - 1;  // Search in the left sub-array
                }
            }
        }
        
        return false; 
    }
};
