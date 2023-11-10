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
        void search(TreeNode *root, int k, int &nodeCount, int &value) {
            if(root == NULL) {
                return;
            }
            
            search(root -> left, k, nodeCount, value);
            
            nodeCount++;
            if(k == nodeCount) {
                value = root -> val;
            }
            
            search(root -> right, k, nodeCount, value);
        }
    
    public:
        int kthSmallest(TreeNode* root, int k) {
            int nodeCount = 0;
            int value;
            search(root, k, nodeCount, value);
            return value;
        }
};