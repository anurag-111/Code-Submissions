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
    int maxDiameter = 0;
    
    int calculateDiameter(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        
        int leftHeight = calculateDiameter(root -> left);
        int rightHeight = calculateDiameter(root -> right);
        
        int height = 1 + max(leftHeight, rightHeight);
        
        int currentDiameter = leftHeight + rightHeight;
        
        maxDiameter = max(currentDiameter, maxDiameter);
        
        return height;            
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDiameter(root);
        return maxDiameter;
    }
};