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
        void traversal(TreeNode *root, vector<string> &treePaths, string str) {            
            if(root == NULL) {
                return;
            }
            
            str += to_string(root -> val);
            
            if(root -> left == NULL && root -> right == NULL) {
                treePaths.push_back(str);
            }
            
            if(root -> left) {
                traversal(root -> left, treePaths, str + "->");
            } 
            
            if(root -> right) {
                traversal(root -> right, treePaths, str + "->");
            }
            
            return;
        }   
    
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> treePaths;
            traversal(root, treePaths, "");
            return treePaths;
        }
};