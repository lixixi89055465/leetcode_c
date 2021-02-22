//
// Created by nanji on 2/22/21.
//
#include "vector"
#include "string"

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {

    }

    void DFS(std::vector<std::vector<int>> &mark,
             std::vector<std::vector<char>> &grid,
             int x, int y) {
        mark[x][y] = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, -1};
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= mark.size() ||
                newy < 0 || newy >= mark[newx].size()) {
                continue;
            }
            if (grid[newx][newy] == '1' && mark[newx][newy] == 0) {
                DFS(mark, grid, newx, newy);
            }
        }
    }
};