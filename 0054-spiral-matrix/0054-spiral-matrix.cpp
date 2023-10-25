class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // left to right
        // top to bottom
        // right to left
        // bottom to top
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> result;
        if(rows == 0) {
            return result;
        }
        
        int left = 0, right = cols - 1;
        int top = 0, bottom = rows - 1;
        
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if(top > bottom || right < left) {
                break;
            }
            
            for(int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            for(int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return result;
    }
};


