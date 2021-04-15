//
// Created by nanji on 4/15/21.
//
/**
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [0]
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "vector"

class Solution {
public:
    int subRob(std::vector<int> &nums, int start, int end) {
        int max = 0;
        std::vector<int> dp;
        dp.push_back(nums[start]);
        dp.push_back(nums[start] > nums[start + 1] ? nums[start] : nums[start + 1]);

        for (int i = start + 2; i < end; i++) {
            dp.push_back(std::max(dp[i - start - 2] + nums[i], dp[i - start - 1]));
        }
        return dp.back();
    }

    int rob(std::vector<int> &nums) {
        if (nums.size() == 0) {
            return nums[0];
        } else if (nums.size() == 1) {
            return nums[1] > nums[0] ? nums[1] : nums[0];
        } else if (nums.size() == 2) {
            return std::max(std::max(nums[0], nums[1]), nums[2]);
        }
        int left = subRob(nums, 0, nums.size() - 1);
        int right = subRob(nums, 1, nums.size());
        return left > right ? left : right;
    }
};

int main() {
    Solution solve;
//    std::vector<int> tmp = {9, 6, 10, 12, 5, 1, 3, 1, 1, 1};
    std::vector<int> tmp = {0, 0};
    int result = solve.rob(tmp);
    printf("result is %d \n", result);
    return 0;
}