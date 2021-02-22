//
// Created by nanji on 2/22/21.
//
#include "vector"
#include "string"
#include "queue"

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {

    }

    void BFS(std::vector<std::vector<int>> &mark,
             std::vector<std::vector<char>> &grid,
             int x, int y) {
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        std::queue<std::pair<int, int>> Q;// 宽度优先搜索队列
        Q.push(std::make_pair(x, y));
        mark[x][y] = 1;
        while (!Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = dx[i] + x;
                int newy = dy[i] + y;
                if (newx < 0 || newx >= mark.size() ||
                    newy < 0 || newy >= mark[newx].size()) {
                    continue;
                }
                if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
                    Q.push(std::make_pair(newx, newy));
                    mark[newx][newy] = 1;
                }
            }
        }

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