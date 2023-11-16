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
        vector<vector<int>> result;
    
        void bfs(TreeNode *root) {
            if(root == NULL) {
                return;
            }
            
            int leftToRight = true;
            
            queue<TreeNode*> q;
            q.push(root);
            
            while(!q.empty()) {
                int size = q.size();
                
                vector<int> currentLevel;
                
                for(int i = 0; i < size; i++) {
                    TreeNode *node = q.front();
                    q.pop();
                    
                    if(leftToRight == true) {
                        currentLevel.push_back(node -> val);
                    } else {
                        currentLevel.insert(currentLevel.begin(), node -> val);
                    }
                    
                    if(node -> left) {
                        q.push(node -> left);
                    }
                    
                    if(node -> right) {
                        q.push(node -> right);
                    }
                }
                
                leftToRight = !leftToRight;
                
                result.push_back(currentLevel);                
            }
        }
    
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(root == NULL) {
                return result;
            }
            
            bfs(root);
            
            return result;
        }
};