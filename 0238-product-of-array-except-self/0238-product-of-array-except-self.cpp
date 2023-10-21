class Solution {
    public : 
        vector<int> productExceptSelf(vector<int> &nums) {
            vector<int> resultSum(nums.size(), 1);
            int product = 1;
            
            // Prefix traversal
            for(int i = 0; i < nums.size(); i++) {
                resultSum[i] = resultSum[i] * product;
                product = product * nums[i];
            }
            
            product = 1;
            // Suffix traversal
            for(int i = nums.size() - 1; i >= 0; i--) {
                resultSum[i] = resultSum[i] * product;
                product = product * nums[i];
            }
            
            return resultSum;
        }
};
