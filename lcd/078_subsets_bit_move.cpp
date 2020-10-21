//
// Created by nanji on 2020/10/20.
//
#include "stdio.h"
#include "vector"

class Solution {
public:
    std::vector<std::vector<int>> subSet(std::vector<int> &nums) {
        int subSet = 1 << nums.size();
        std::vector<std::vector<int>> result;
        for (int i = 0; i < subSet; i++) {
            std::vector<int> item;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    Solution solve;
    std::vector<std::vector<int>> result = solve.subSet(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
}
