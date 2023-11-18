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
        int findMaxDiff(TreeNode *root, int minVal, int maxVal) {
            if(root == NULL) {
                return abs(maxVal - minVal);
            }
            
            minVal = min(minVal, root -> val);
            maxVal = max(maxVal, root -> val);
            
            int leftVal = findMaxDiff(root -> left, minVal, maxVal);
            int rightVal = findMaxDiff(root -> right, minVal, maxVal);
            
            return max(leftVal, rightVal);
        }
    
    public:
        int maxAncestorDiff(TreeNode *root) {
            return findMaxDiff(root, root -> val, root -> val);
        }
};