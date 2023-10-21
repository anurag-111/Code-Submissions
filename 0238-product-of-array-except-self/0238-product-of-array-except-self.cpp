class Solution {
    public : 
        vector<int> productExceptSelf(vector<int> &nums) {
            vector<int> prefixSum(nums.size(), 1);
            vector<int> suffixSum(nums.size(), 1);
            vector<int> resultSum(nums.size(), 1);
            int product = 1;
            
            // Prefix traversal
            for(int i = 0; i < nums.size(); i++) {
                prefixSum[i] = prefixSum[i] * product;
                product = product * nums[i];
            }
            
            product = 1;
            // Suffix traversal
            for(int i = nums.size() - 1; i >= 0; i--) {
                suffixSum[i] = suffixSum[i] * product;
                product = product * nums[i];
            }
            
            // Calculation of result traversal
            for(int i = 0; i < nums.size(); i++) {
                resultSum[i] = prefixSum[i] * suffixSum[i];
            }
            
            return resultSum;
        }
};
