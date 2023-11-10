/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root -> val == p -> val || root -> val == q -> val) {
            return root;
        }
        
        TreeNode *leftVal = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rightVal = lowestCommonAncestor(root -> right, p, q);
        
        if(leftVal == NULL) {
            return rightVal;
        } else if(rightVal == NULL) {
            return leftVal;
        }
        
        return root;
    }
};