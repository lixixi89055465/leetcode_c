//
// Created by nanji on 4/7/21.
/**
 *
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。



示例 1：

输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true
示例 2：

输入：nums = [2,5,6,0,0,1,2], target = 3
输出：false
 5,6,7,8,1,2,3,4,
 5,6,7,8,9,2,3,4,
 6,7,8,-1,0,1,2,3,4,
 1,2,3,4,5,6,7,8,
 */
//

#include "vector"

class Solution {
public:
    bool search(std::vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] < nums[right]) {
                break;
            } else if (nums[left] > nums[right]) {
                if (nums[left] < nums[mid]) {
                    if (target >= nums[left] && target <= nums[mid]) {
                        right = mid - 1;
                        break;
                    } else {
                        left = mid + 1;
                    }
                } else if (nums[left] > nums[mid]) {
                    if (target > nums[mid] && target <= nums[right]) {
                        left = mid + 1;
                        break;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    left++;
                }
            } else {
                left++;
            }

        }

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

};

int main() {
    Solution solve;
//    std::vector<int> nums = {0, 1, 2, 3, 4,  6, 7, 8, 9};
//    bool result = solve.search(nums, 2);
//    bool result = solve.search(nums, 5);
//    std::vector<int> nums = {2, 3, 4, 6, 7, 8, 9, 0, 1};
//    std::vector<int> nums = {1, 0, 1, 1, 1};
//    std::vector<int> nums = {3,1};
    std::vector<int> nums = {3, 5, 1};
//    std::vector<int> nums = {5, 1, 3};
//    bool result = solve.search(nums, 0);
//    bool result = solve.search(nums, 1);
//    bool result = solve.search(nums, 2);
    bool result = solve.search(nums, 3);
//    bool result = solve.search(nums, 4);
//    bool result = solve.search(nums, 5);
//    bool result = solve.search(nums, 6);
//    bool result = solve.search(nums, 7);
//    bool result = solve.search(nums, 8);
//    bool result = solve.search(nums, 0);
//    bool result = solve.search(nums, 5);
    printf("%d\n", result);
    return 0;
}
/**
 * 方法一：二分查找
思路

对于数组中有重复元素的情况，二分查找时可能会有 a[l]=a[\textit{mid}]=a[r]a[l]=a[mid]=a[r]，此时无法判断区间 [l,\textit{mid}][l,mid] 和区间 [\textit{mid}+1,r][mid+1,r] 哪个是有序的。

例如 \textit{nums}=[3,1,2,3,3,3,3]nums=[3,1,2,3,3,3,3]，\textit{target}=2target=2，首次二分时无法判断区间 [0,3][0,3] 和区间 [4,6][4,6] 哪个是有序的。

对于这种情况，我们只能将当前二分区间的左边界加一，右边界减一，然后在新区间上继续二分查找。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-ii-by-l-0nmp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
