//
// Created by nanji on 1/13/21.
//

#include "stdio.h"
#include "vector"

class Solution {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        std::vector<int> result;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target == nums[mid]) {
                result.push_back(begin);
                result.push_back(end);
                return result;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                begin = mid + 1;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};

int main() {
    int test[] = {1, 3, 5, 6};
    std::vector<int> nums;
    Solution solve;
    for (int i = 0; i < 4; i++) {
        nums.push_back(test[i]);
    }

//    printf("i= %d  index= %d \n", i, solve.searchRange(nums, i));
    std::vector<int> result = solve.searchRange(nums, 4);
    for (int i = 0; i < result.size(); i++) {
        printf("%d\t", result[i]);
    }

    return 0;
}

