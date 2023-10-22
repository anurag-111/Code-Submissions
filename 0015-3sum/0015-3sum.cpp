class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            // Ignoring the 1st duplicative element
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            int target = - (nums[i]);
            
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    
                    // Ignoring the 2nd duplicative element
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Ignoring the 3rd duplicative element
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;                       
                } else if(sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return triplets;
    }
};