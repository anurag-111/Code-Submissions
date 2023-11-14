class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        vector<vector<int>> visited(rows, vector<int> (cols, 0));
        vector<vector<int>> distance(rows, vector<int> (cols, 0));
        
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                } else {
                    visited[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[r][c] = steps;
            
            // Valid indexes traversal
            for(int i = 0; i < 4; i++) {
                int nrows = r + delRow[i];
                int ncols = c + delCol[i];
                
                if(nrows >= 0 && ncols >= 0 && nrows < rows && ncols < cols && visited[nrows][ncols] == 0) {
                    visited[nrows][ncols] = 1;
                    q.push({{nrows, ncols}, steps + 1});
                }
            }
        }
        
        return distance;
        
    }
};