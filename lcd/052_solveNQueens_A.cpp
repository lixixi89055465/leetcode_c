//
// Created by nanji on 2020-10-25.
//

#include "vector"
#include "string"

class Solution {
public:
    std::vector<std::vector<std::string>> solveQueen(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::vector<int>> mark;
        std::vector<std::string> location;
        for (int i = 0; i < n; i++) {
            mark.push_back((std::vector<int>()));
            for (int j = 0; j < n; j++) {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, result, mark);
        return result;
    }

    void generate(int k, int n,//
                  std::vector<std::string> &location,//
                  std::vector<std::vector<std::string>> &result,//
                  std::vector<std::vector<int>> &mark) {
        if (k >= n) {
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (mark[k][i] == 0) {
                std::vector<std::vector<int>> tmp_mark = mark;
                location[k][i] = 'Q';
                put_down_the_queue(k, i, mark);
                generate(k + 1, n, location, result, mark);
                mark = tmp_mark;
                location[k][i] = '.';
            }
        }
    }

    void put_down_the_queue(int x, int y, std::vector<std::vector<int>> &mark) {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); i++) {
            for (int j = 0; j < 8; j++) {
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                    mark[new_x][new_y] = 1;
                }
            }
        }

    }
};

int main() {
    Solution solve;
    std::vector<std::vector<std::string>> result = solve.solveQueen(5);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%s\n", result[i][j].c_str());
        }
        printf("\n\n");
    }
    return 0;
}
