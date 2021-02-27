//
// Created by nanji on 2/26/21.
//

#include "vector"
#include "queue"

struct Qitem {
    int x;
    int y;
    int h;

    Qitem(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
};

struct cmp {
    bool operator()(const Qitem &a, const Qitem &b) {
        return a.h > b.h;
    }
};


class Solution {
public:
    int trapRainWater(std::vector<std::vector<int>> &heightMap) {
        std::priority_queue<Qitem, std::vector<Qitem>, cmp> Q;
        if (heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }
        int row = heightMap.size();
        int column = heightMap[0].size();
        std::vector<std::vector<int>> mark;
        for (int i = 0; i < row; i++) {
            mark.push_back(std::vector<int>());
            for (int j = 0; j < column; j++) {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < row; i++) {
            Q.push(Qitem(i, 0, heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i, column - 1, heightMap[i][column - 1]));
            mark[i][column - 1] = 1;
        }
        for (int i = 1; i < column - 1; i++) {
            Q.push(Qitem(0, i, heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row - 1, i, heightMap[row - 1][i]));
            mark[row - 1][i] = 1;
        }
        static const int dx[] = {-1, 1, 0, 0};//方向数组
        static const int dy[] = {0, 0, -1, 1};
        int result = 0;  //最终积水量
        while (!Q.empty()) {
            int x = Q.top().x; //取队列头部信息
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dy[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= row ||
                    newy < 0 || newy >= column || mark[newx][newy]) {
                    continue;//当新拓展的点超出边界或已加入队列
                }
                if (h > heightMap[newx][newy]) { //当前点的高度高于拓展点时
                    result += heightMap[newx][newy] - h;
                    heightMap[newx][newy] = h;
                }
                Q.push(Qitem(newx, newy, heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }

        }
        return result;
    }
};

int main() {
    std::priority_queue<Qitem, std::vector<Qitem>, cmp> Q;
    Q.push(Qitem(0, 0, 5));
    Q.push(Qitem(1, 3, 2));
    Q.push(Qitem(5, 2, 4));
    Q.push(Qitem(0, 1, 8));
    Q.push(Qitem(6, 7, 1));
    while (!Q.empty()) {
        int x = Q.top().x;
        int y = Q.top().y;
        int h = Q.top().h;
        printf("x=%d y=%d h=%d\n", x, y, h);
        Q.pop();
    }
    return 0;
}


