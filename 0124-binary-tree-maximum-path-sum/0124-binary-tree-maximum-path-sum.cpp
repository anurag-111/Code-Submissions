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
public:
    int calculateSum(TreeNode *root, int &maxPathSum) {
        if(root == NULL) {
            return 0;
        }
        
        int left = calculateSum(root -> left, maxPathSum);
        int right = calculateSum(root -> right, maxPathSum);
        
        int maxLeftOrRight = max(left, right);
        
        int maxToReturn = max(root -> val + maxLeftOrRight, root -> val);
        
        int currentPathSum = max(root -> val + left + right, maxToReturn);
        
        maxPathSum = max(maxPathSum, currentPathSum);
        
        return maxToReturn;
    }
    
    int maxPathSum(TreeNode *root) {
        int maxPathSum = root -> val;
        calculateSum(root, maxPathSum);
        return maxPathSum;
    }
};