//
// Created by nanji on 2020/10/20.
//
#include <algorithm>
#include "stdio.h"
#include "vector"
#include "set"

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;// 去重 使用的集合 set
        std::sort(nums.begin(), nums.end()); //对nums 数组进行排序
        result.push_back(item);

        generate(0, item, nums, result, res_set);
        return result;
    }

private:
    void generate(int i, std::vector<int> &item, std::vector<int> &nums, std::vector<std::vector<int>> &result,
                  std::set<std::vector<int>> &res_set) {
        if (i >= nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end()) {
            result.push_back(item);
            res_set.insert(item);
        }

        generate(i + 1, item, nums, result, res_set);
        item.pop_back();
        generate(i + 1, item, nums, result, res_set);
    }
};

int main() {
    printf("aaaaaa");
    Solution solve;
    std::vector<std::vector<int>> result;
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);

    result = solve.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++) {
        if (result[i].size() == 0) {
            printf("[ ] ");
        }
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%d] ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

