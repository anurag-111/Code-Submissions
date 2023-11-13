class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;

        queue<pair<int, int>> rottenOranges;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        rottenOranges.push({-1, -1});
        int minutes = -1;

        while (!rottenOranges.empty()) {
            int row = rottenOranges.front().first;
            int col = rottenOranges.front().second;
            rottenOranges.pop();

            if (row == -1) {
                minutes++;
                if (!rottenOranges.empty()) {
                    rottenOranges.push({-1, -1});
                }
            } else {
                for (const auto& dir : dirs) {
                    int x = row + dir[0];
                    int y = col + dir[1];

                    if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        freshOranges--;
                        rottenOranges.push({x, y});
                    }
                }
            }
        }

        return (freshOranges != 0) ? -1 : minutes;
    }
};
