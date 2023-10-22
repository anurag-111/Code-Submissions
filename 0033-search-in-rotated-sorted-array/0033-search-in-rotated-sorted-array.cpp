// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104


// Func name : search
// return : int
// parameters : nums, target

class Solution {
  public :
        int search(vector<int> &nums, int target) {
            int low = 0;
            int high = nums.size() - 1;
            
            while(low <= high) {
                int mid = low + (high - low) / 2;
                
                // Check if we found the target
                if(nums[mid] == target) {
                    return mid;
                }
                
                // Check if the left sub-array is sorted
                if(nums[low] <= nums[mid]) {
                    // Now check for the target to exist in this range
                    if(nums[low] <= target && target <= nums[mid]) {
                        // Target exists in this range
                        high = mid - 1;
                    } else {
                        // Target does not exists in this range
                        low = mid + 1;
                    }   
                } 
                
                // Check if the right sub-array is sorted
                else if(nums[mid] <= nums[high]) {
                    // Now check for the target to exist in this range
                    if(nums[mid] <= target && target <= nums[high]) {
                        // Target exists in this range
                        low = mid + 1;
                    } else {
                        // Target does not exists in this range
                        high = mid - 1;
                    }
                }
            }            
            
            return -1;
        }
};


























