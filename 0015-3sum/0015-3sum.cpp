class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            // Ignoring the first duplicatie element
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -(nums[i]);
            
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    // Found the triplet
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    
                    // Ignoring the second duplicatie element
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Ignoring the third duplicative element
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