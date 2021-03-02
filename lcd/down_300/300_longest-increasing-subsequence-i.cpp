//
// Created by nanji on 3/1/21.
// 求数组最长上升子序列的长度
//
#include "vector"

class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        std::vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                for (int j = 0; j < stack.size(); j++) {
                    if (stack[j] >= nums[i]) {
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};


