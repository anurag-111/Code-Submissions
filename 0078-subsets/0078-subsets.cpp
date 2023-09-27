class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int N = nums.size();
        int subsetsCount = (1 << N);
        vector<vector<int>> subsets;
        

        for(int mask = 0; mask < subsetsCount; mask++) {
            vector<int> subset;
            for(int i = 0; i < N; i++) {
                if((mask & (1 << i)) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }

        return subsets;
    }
};