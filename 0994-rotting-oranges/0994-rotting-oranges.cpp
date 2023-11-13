class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int, int>, int>> rottenQueue;
        int visited[rows][cols];
        int freshOrangesCount = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If cell contains a rotten orange
                if (grid[i][j] == 2) {
                    rottenQueue.push({{i, j}, 0});
                    // Mark as visited (rotten) in the visited array
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }

                // Count fresh oranges
                if (grid[i][j] == 1) {
                    freshOrangesCount++;
                }
            }
        }

        int timer = 0;
        // Delta row and delta column
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        int rottenOrangesCount = 0;

        // BFS traversal (until the queue becomes empty)
        while (!rottenQueue.empty()) {
            int row = rottenQueue.front().first.first;
            int col = rottenQueue.front().first.second;
            int time = rottenQueue.front().second;
            timer = max(timer, time);
            rottenQueue.pop();

            // Exactly 4 neighbors
            for (int i = 0; i < 4; ++i) {
                // Neighboring row and column
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];

                // Check for a valid cell and then for an unvisited fresh orange
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1) {
                    // Push in the queue with the timer increased
                    rottenQueue.push({{newRow, newCol}, time + 1});
                    // Mark as rotten
                    visited[newRow][newCol] = 2;
                    rottenOrangesCount++;
                }
            }
        }

        // If not all oranges are rotten
        if (rottenOrangesCount != freshOrangesCount) {
            return -1;
        }

        return timer;
    }
};