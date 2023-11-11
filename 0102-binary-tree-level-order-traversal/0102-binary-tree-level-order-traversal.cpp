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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) {
            return result;
        }

        
        queue <TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()) {
            int size = nodeQueue.size();
            vector<int> currentLevel;
            
            for(int i = 0; i < size; i++) {
                TreeNode *node = nodeQueue.front();
                nodeQueue.pop();
                
                currentLevel.push_back(node -> val);
                
                if(node -> left) {
                    nodeQueue.push(node -> left);
                } 
                
                if(node -> right) {
                    nodeQueue.push(node -> right);
                }
            }
            
            result.push_back(currentLevel);
        }
        
        return result;       
    }
};