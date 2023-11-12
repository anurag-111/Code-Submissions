#include <vector>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';

        DFS(board, i + 1, j);
        DFS(board, i, j + 1);
        DFS(board, i - 1, j);
        DFS(board, i, j - 1);
    }

    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) {
            return;
        }

        for (int i = 0; i < board[0].size(); i++) {
            // For the first row
            if (board[0][i] == 'O') {
                DFS(board, 0, i);
            }
            // For the last row
            if (board[board.size() - 1][i] == 'O') {
                DFS(board, board.size() - 1, i);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            // For the first column
            if (board[i][0] == 'O') {
                DFS(board, i, 0);
            }

            // For the last column
            if (board[i][board[0].size() - 1] == 'O') {
                DFS(board, i, board[0].size() - 1);
            }
        }

        // Now, mark surrounded 'O's with 'X'
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
