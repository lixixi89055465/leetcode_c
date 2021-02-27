//
// Created by nanji on 2020-10-16.
//

#include "stdio.h"
#include "algorithm"
#include "vector"

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first < b.first; //无需考虑左端点相同时的排序
}

class Solution {
public:
    int findMinArrowShots(std::vector<std::pair<int, int>> &points) {
        if (points.size() == 0) {
            return 0; //传入的数据可能为空，直接返回0
        }
        std::sort(points.begin(), points.end(), cmp);//对气球按照左端点从小到大排序
        //初始化弓箭手数量为1
        int shoot_num = 1;
        int shoot_begin = points[0].first;
        int shoot_end = points[0].second; //初始化射击空间，即为第一个气球的两端点

        for (int i = 1; i < points.size(); i++) {
            if (points[i].first <= shoot_end) {
                shoot_begin = points[i].first;
                if (shoot_end > points[i].second) {
                    shoot_end = points[i].second;
                }
            } else {
                shoot_num++;
                shoot_begin = points[i].first;//
                shoot_end = points[i].second;// 再保证当前球体被射穿的条件下，射击区间不能再更新了，需要增加一个新的射击区间了。
            }
        }
        return shoot_num;
    }
};
int main(){
    std::vector<std::pair<int,int>>points;
    points.push_back(std::make_pair(10,16));
    points.push_back(std::make_pair(2,8));
    points.push_back(std::make_pair(1,6));
    points.push_back(std::make_pair(7,12));
    points.push_back(std::make_pair(17,19));
    Solution solve;
    printf("%d \n",solve.findMinArrowShots(points));
    return 0;
}
