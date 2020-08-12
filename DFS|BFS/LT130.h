//
// Created by h4h4da on 8/11/20.
//

#include <vector>

using namespace std;
#ifndef LEETCODE_LT130_H
#define LEETCODE_LT130_H


/**
 * LeetCode  被围绕的区域
 * DFS 反向思考，搜索出与边缘相连的O，剩余的O则是满足条件的
 */
class LT130 {

    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        //防止重复遍历
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        //记录当前的位置 是否合法
        vector<vector<bool>> valid = vector<vector<bool>>(n, vector<bool>(m, true));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && i != n - 1) {
                    if (j != 0) {
                        j = m - 1;
                    }
                }
                traverse(i, j, board, visited, valid);
            }
        }
        fillWithX(board, valid);
    }

    /**
     * 替换O
     * @param board
     * @param valid
     */
    void fillWithX(vector<vector<char>> &board, vector<vector<bool>> &valid) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (valid[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void traverse(int x,
                  int y,
                  vector<vector<char>> &board,
                  vector<vector<bool>> &visited,
                  vector<vector<bool>> &valid
    ) {
        int n = board.size();
        int m = board[0].size();
        if (!isInRange(x, y, n, m)) return;
        if (visited[x][y]) return;
        visited[x][y] = true;
        if (board[x][y] == 'X') return;
        valid[x][y] = false;
        traverse(x + 1, y, board, visited, valid);
        traverse(x - 1, y, board, visited, valid);
        traverse(x, y + 1, board, visited, valid);
        traverse(x, y - 1, board, visited, valid);
    }

    bool isInRange(int x, int y, int maxX, int maxY) {
        return x >= 0 && x < maxX && y >= 0 && y < maxY;
    }

};


#endif //LEETCODE_LT130_H
