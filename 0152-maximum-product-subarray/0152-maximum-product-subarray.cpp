class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftProduct = 1;
        int rightProduct = 1;
        int maxProduct = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            leftProduct = leftProduct == 0 ? 1 : leftProduct;
            rightProduct = rightProduct == 0 ? 1 : rightProduct;
            
            leftProduct = leftProduct * nums[i];
            rightProduct = rightProduct * nums[nums.size() - i -1];
            
            maxProduct = max(maxProduct, max(leftProduct, rightProduct));
        }
        
        return maxProduct;
    }
};