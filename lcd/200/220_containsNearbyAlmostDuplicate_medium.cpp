//
// Created by nanji on 4/17/21.
//
/**
 * 220. 存在重复元素 III
 * 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在两个下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

 

示例 1：

输入：nums = [1,2,3,1], k = 3, t = 0
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1, t = 2
输出：true
示例 3：

输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "vector"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
        if (nums.size() <= 1) {
            return false;
        }
        if (k == 0) {
            return false;
        }
        long t1 = (long) t;
        long left = 0, right = 0;
        int i = 0, j = 0;
        for (i = 0; i < nums.size() - 1; i++) {
            left = nums[i];
            for (j = 1; j <= k && (i + j) < nums.size(); j++) {
                right = nums[i + j];
                if (std::abs(left - right) <= t1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solve;
//    std::vector<int> nums = {1, 2, 3, 1};
//    int k = 3, t = 0;
//    std::vector<int> nums={1,0,1,1};
//    int k=1,t=2;
//    std::vector<int> nums = {1, 5, 9, 1, 5, 9};
//    int k = 2, t = 3;
//    std::vector<int> nums = {1, 2};
//    int k = 0, t = 1;
    std::vector<int> nums = {1, 1};
    int k = 1, t = 0;

    bool result = solve.containsNearbyAlmostDuplicate(nums, k, t);
    printf("%d\n", result);
    return 0;
}
