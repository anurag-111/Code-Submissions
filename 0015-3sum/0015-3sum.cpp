class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            // Ignoring the duplicative 1st number
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -(nums[i]);
            int left = i + 1;
            int right = nums.size() - 1;
            
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum < target) {
                    left++;
                } else if(sum > target) {
                    right--;
                } else {
                    // Found
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    // Ignoring the duplicative 2nd number
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Ignoring the duplicative 3rd number
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }
        return triplets;
    } 
};