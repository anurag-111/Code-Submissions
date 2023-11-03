class Solution {
public:
    int nodeValue = 0;
    
    void inorderTraversal(TreeNode *root, int &nodeCount, int k) {
        if(root == NULL) {
            return;
        }
        
        inorderTraversal(root -> left, nodeCount, k);
        
        nodeCount++;
        if(nodeCount == k) {
            nodeValue = root -> val;
        }
        
        inorderTraversal(root -> right, nodeCount, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int nodeCount = 0;
        inorderTraversal(root, nodeCount, k);
        return nodeValue;
    }
};