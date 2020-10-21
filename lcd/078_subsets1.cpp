//
// Created by nanji on 2020/10/20.
//
#include "stdio.h"
#include "vector"

class Solution {
public:
    void addToResult(int newNode, std::vector<std::vector<int>> &result) {
        for (int i = 0; i < result.size(); i++) {
            std::vector<int> node;
//           node.push_back(result[i]);
            node.push_back(newNode);
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        for (int i = nums[nums.size() - 1]; i >= 0; i--) {
            addToResult(nums[i], result);
        }
        return result;
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    std::vector<int> item;
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
        item.push_back(nums[i]);
        result.push_back(item);
    }
    for (int i = 0; i < result.size(); i++) {
        printf("\n");
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%d]", result[i][j]);
        }
    }
    return 0;
}
