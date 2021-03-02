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
        std::vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (LIS < dp[i]) {
                LIS = dp[i];
            }
        }
    }
};
