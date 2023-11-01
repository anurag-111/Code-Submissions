class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode *leftLCA = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rightLCA = lowestCommonAncestor(root -> right, p, q);
        
        if(leftLCA == NULL) {
            return rightLCA;
        } else if(rightLCA == NULL) {
            return leftLCA;
        }
        
        return root;
    }
};