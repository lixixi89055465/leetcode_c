//
// Created by nanji on 2020-10-16.
//


#include <vector>
#include <queue>
#include "stdio.h"
#include<functional>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first > b.first;
}

class Solution {
public:

    int get_minimum_stop(int L, int P, std::vector<std::pair<int, int>> &stop) {
        int count = 0;
        //存储油量的最大堆
        std::priority_queue<int, std::vector<int>, std::less<int>> q;
        stop.push_back(std::make_pair(0, 0));
        std::sort(stop.begin(), stop.end(), cmp);//以停靠点作为一个
        for (int i = 0; i < stop.size(); i++) {
            int d = L - stop[i].first;
            q.push(stop[i].second);
            while (P < d && !q.empty()) {
                P += q.top();
                q.pop();
                count++;
            }
            if (q.empty()&&P>=d) {
                return -1;
            }
        }
        return count;
    }
};

int main() {
    Solution solve;
    std::vector<std::pair<int, int>> stop;

    stop.push_back(std::make_pair(10, 25));
    stop.push_back(std::make_pair(4, 15));
    stop.push_back(std::make_pair(1, 11));
    stop.push_back(std::make_pair(6, 10));
    stop.push_back(std::make_pair(4, 4));

    int count = solve.get_minimum_stop(25, 15, stop);
    printf("tiankongzhic:%d", count);
    return 0;
}