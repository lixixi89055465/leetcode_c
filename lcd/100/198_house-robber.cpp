//
// Created by nanji on 2/27/21.
//


#include "vector"

class Solution {
public:
    int rob(std::vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return std::max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};

int main() {
    Solution solve;
    std::vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(7);
    printf("%d\n", solve.rob(nums));
    return 0;

}