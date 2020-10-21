//
// Created by nanji on 2020/10/20.
//
#include "stdio.h"
#include "vector"

class Solution {
public:
    void subsets(std::vector<int> &nums, std::vector<std::vector<int>> &result) {
        std::vector<int> item;
        generate(0, item, nums, result);
    }

private:
    void generate(int i, std::vector<int> &item, std::vector<int> &nums, std::vector<std::vector<int>> &result) {
        if (i >= nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i + 1, item, nums, result);
        item.pop_back();
        generate(i + 1, item, nums, result);
    }
};

int main() {
    Solution solve;
    std::vector<std::vector<int>> result;
    std::vector<int> nums;
    for (int i = 0; i < 4; i++) {
        nums.push_back(i);
    }
    solve.subsets(nums, result);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
