//
// Created by nanji on 4/8/21.
//
/**
 * 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 4 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素


 示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
示例 3：

输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
 8,9,1,2,3,4,5,6,7
 */
#include "vector"

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        if (nums.size() < 1) {
            return -1;
        }
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[left] < nums[right]) {
                return nums[left];
            } else if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
                left = mid;
            } else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
            } else {
                left++;
            }
        }
        return nums[left];
    }
};

int main() {
//    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//    std::vector<int> nums = {1};
//    std::vector<int> nums = {2, 1};
    std::vector<int> nums = {3, 1, 2};
    printf("%d\n", nums.size());
    Solution solve;
    int result = solve.findMin(nums);
    printf("%d\n", result);
    return 0;
}


