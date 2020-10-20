//
// Created by nanji on 2020-10-15.
//

#include "vector"
#include "stack"
#include "stdio.h"

class Solution {
public:
    bool canJump(std::vector<int> &nums) {
        std::vector<int> index; //最远可跳至的位置
        for (int i = 0; i < nums.size(); i++) {
            index.push_back(i + nums[i]); //计算index 数组
        }
        int jump = 0;  //初始化jump和max_index //知道jump跳至数组尾部 ， jump 超越了当前可跳的最远位置
        int max_index = index[0];
        while (jump < index.size() && jump <= max_index) {
            if (max_index < index[jump]) {
                max_index = index[jump];// 如果当前可以跳的更远，则更新 max_index
            }
            jump++; //扫描 jump
        }
        if (jump == index.size()) {//若jump达到数组尾，则返回真
            return true;
        }
        return false; //否则返回假
    }
};
