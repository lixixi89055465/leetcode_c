//
// Created by nanji on 2020-10-15.
//

#include "vector"
#include "stack"
#include "stdio.h"

typedef struct ELE {
    int index;
    int stepSize;
} ELE;

class Solution {
public:
    bool canJump(std::vector<int> &nums) {
        std::stack<ELE> stack;
        int index = 0;
        ELE first = {index, nums[index]};
        stack.push(first);
        index += nums[index];

        while (index < nums.size() && stack.size() > 0) {
            printf("first.stepSize:%d; first.index : %d ; size : %d\n", first.stepSize, first.index, stack.size());
            printf("top: %d; %d \n", stack.top().index, stack.top().stepSize);
            if (nums.at(index) <= 0) {
                ELE ele = stack.top();
                if (ele.stepSize > 1) {
                    ele.stepSize--;
                    index--;
                } else {
//                    printf("begin index:%d", index);
//                    index -= 1;
//                    printf("end index %d \n", index);
//                    stack.pop();
//                    printf("stepSize: %d\t", stack.top().stepSize);
//                    stack.top().stepSize--;
//                    printf("stepSize : %d\n", stack.top().stepSize);
                    while (!stack.empty() && stack.top().stepSize == 1) {
                        index--;
                        stack.pop();
                    }
                    if(!stack.empty()) {
                        stack.top().stepSize--;
                    }
                }
            } else {
                ELE ele = {index, nums[index]};
                stack.push(ele);
                index += nums[index];
            }
        }
        if (index >= nums.size()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);

    bool a = solution.canJump(nums);
    printf("tian %d", a);
}