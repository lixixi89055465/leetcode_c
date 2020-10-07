//
// Created by nanji on 2020/10/7.
//

#include "stdio.h"
#include<vector>
#include<algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
        std::sort(g.begin(), g.end());//对孩子的需求因子g与糖果大小s两数组排序
        std::sort(s.begin(), s.end());
        int child = 0;//child代表已经满足了几个孩子 ，cookie代表尝试了几个糖果
        int cookie = 0;
        while (child < g.size() && cookie < s.size()) { //当孩子或者糖果同时均未尝试完时
            if (g[child] <= s[cookie]) {//当孩子的满足因子小于或等于糖果大小的时
                child++;//当糖果满足了孩子，孩子指针child向后移动
            }
            cookie++; //无论成功或失败，每个糖果只尝试一次，cookie 向后移动
        }
        return child;//最终child 即为得到满足的孩子的个数
    }
};

int main() {
    Solution solve;
    std::vector<int> g;
    std::vector<int> s;
    g.push_back(5);
    g.push_back(10);
    g.push_back(2);
    g.push_back(9);
    g.push_back(15);
    g.push_back(9);

    s.push_back(1);
    s.push_back(20);
    s.push_back(3);
    s.push_back(8);
    s.push_back(5);
    printf("%d \n", solve.findContentChildren(g, s));
    return 0;
}