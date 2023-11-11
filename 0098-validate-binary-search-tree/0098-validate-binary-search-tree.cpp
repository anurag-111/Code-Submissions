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
    bool validateBST(TreeNode *root, long long minVal, long long maxVal) {
        // base condition
        if(root == NULL) {
            return true;
        }
        
        // processing conditions
        if((root != NULL && root -> val <= minVal) || (root != NULL && root -> val >= maxVal)) {
            return false;
        }
        
        // function calls
        bool leftValidation = validateBST(root -> left, minVal, root -> val);
        bool rightValidation = validateBST(root -> right, root -> val, maxVal);
        
        return leftValidation && rightValidation;
    }
    
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LLONG_MIN, LLONG_MAX);
    }
};