class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            // Duplicate 1st
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            int target = - (nums[i]);

            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum < target) {
                    left++;
                } else if(sum > target) {
                    right--;
                } else{
                    // Found
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    // Duplicate 2nd
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Duplicate 3rd
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move pointers
                    left++;
                    right--;
                }
            }
        }
        return triplets;
    }
};