/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        int calculatePathSum(TreeNode *root, int &maxPathSum) {
            if(root == NULL) {
                return 0;
            }
            
            int left = calculatePathSum(root -> left, maxPathSum);
            int right = calculatePathSum(root -> right, maxPathSum);
            
            // Calculating the maximum path of child nodes
            int maxLeftOrRight = max(left, right);
            
            // Root + child value or just the root node itself
            int maxToReturn = max(root -> val + maxLeftOrRight, root -> val);
            
            // Where the current sub-tree is the greatest path sum
            int currentPathSum = max(root -> val + left + right, maxToReturn);
            
            maxPathSum = max(maxPathSum, currentPathSum);
            
            return maxToReturn;
        }
    
    public:
        int maxPathSum(TreeNode* root) {
            int maxPathSum = root -> val;
            calculatePathSum(root, maxPathSum);
            return maxPathSum;
        }
};