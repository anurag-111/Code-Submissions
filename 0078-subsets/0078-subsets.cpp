class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        int mask = 0;
        int n = nums.size();
        int subsetsCount = (1 << n);

        for(int mask = 0; mask < subsetsCount; mask++) {
            vector<int> subset;
            for(int i = 0; i < n; i++) {
                if((mask & (1 << i)) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }

        return subsets;
    }
};