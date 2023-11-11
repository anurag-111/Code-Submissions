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
    TreeNode *constructFunc(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int left, int right, unordered_map<int, int> &nodeToIndex) {
        if(left > right) {
            return NULL;
        }
        
        int pivotIndex = nodeToIndex[preorder[preorderIndex++]];
        
        TreeNode *node = new TreeNode(inorder[pivotIndex]);
        
        node -> left = constructFunc(preorder, inorder, preorderIndex, left, pivotIndex - 1, nodeToIndex);
        node -> right = constructFunc(preorder, inorder, preorderIndex, pivotIndex + 1, right, nodeToIndex);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        unordered_map<int, int> nodeToIndex;
        
        for(int i = 0; i < preorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
        
        return constructFunc(preorder, inorder, preorderIndex, 0, preorder.size() - 1, nodeToIndex);
    }
};