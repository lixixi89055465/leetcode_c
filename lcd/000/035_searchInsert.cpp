//
// Created by nanji on 1/13/21.
//

#include "stdio.h"
#include "vector"

class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                begin = mid + 1;
            }
        }
        nums.push_back(target);
        for (int i = nums.size() - 2; i > mid; i--) {
            nums[i + 1] = nums[i];
        }
        nums[mid] = target;
        return mid;
    }
};

int main() {
    int test[] = {1, 3, 5, 6};
    std::vector<int> nums;
    Solution solve;
    for (int i = 0; i < 4; i++) {
        nums.push_back(test[i]);
    }
    for (int i = 0; i < 8; i++) {
        printf("i= %d  index= %d \n", i, solve.searchInsert(nums, i));
    }
    for (int i = 0; i < nums.size(); i++) {
        printf("%d\t", nums[i]);
    }

    return 0;
}

