//
// Created by nanji on 2020-10-15.
//

#include "stdio.h"
#include "vector"
#include "stack"

class Solution {
public:
    int canJump(std::vector<int> &nums) {
        std::stack<int> stack;
        stack.push(0);
        int jumpCount = 0;
        int index = 0;
        int current_max_index = nums[0];
        while (index + nums[index] < nums.size()) {
            current_max_index = nums[index] + index;
            int pre_max_index = index + 1;
            while (pre_max_index < index + nums[index]) {
                if (pre_max_index + nums[pre_max_index] > current_max_index + nums[current_max_index]) {
                    current_max_index = pre_max_index;
                }
                pre_max_index++;
            }
            index = current_max_index;
            jumpCount++;

        }
        return jumpCount;
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(9);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    Solution solution;
    int count = solution.canJump(nums);
    printf("%d\n", count);
    printf("finish");
    return 0;
}
