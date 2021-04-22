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
    void removeOld(std::vector<int> &nums, int oldE) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < oldE) {
                left = mid + 1;
            } else if (nums[mid] > oldE) {
                right = mid - 1;
            } else {
                break;
            }
        }
        std::vector<int>::iterator it = nums.begin() + mid;
        nums.erase(it);
    }

    bool addNew(std::vector<int> &nums, int ele, int t) {
        long l1, l2, t1;
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < ele) {
                left = mid + 1;
            } else if (nums[mid] > ele) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        std::vector<int>::iterator it = nums.begin() + left;
        nums.insert(it, ele);
        if (left + 1 < nums.size()) {
            l1 = nums[left], l2 = nums[left + 1], t1 = (long) t;
            if (l2 - l1 <= t1) {
                return true;
            }
        }
        if (left - 1 >= 0) {
            l2 = nums[left], l1 = nums[left - 1], t1 = (long) t;
            if (l2 - l1 <= t1) {
                return true;
            }
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
        if (nums.size() <= 1) {
            return false;
        }
        if (k == 0) {
            return false;
        }
        if (k > nums.size()) {
            k = nums.size();
        }
        std::vector<int> tmpVec;
        for (int i = 0; i < k + 1; i++) {
            tmpVec.push_back(nums[i]);
        }
        std::sort(tmpVec.begin(), tmpVec.end());
        long left = 0, right = 0;
        long t1 = (long) t;
        for (int i = 0; i < tmpVec.size() - 1; i++) {
            left = (long) tmpVec[i];
            right = (long) tmpVec[i + 1];
            if (std::abs(right - left) <= t1) {
                return true;
            }
        }
        int i = 0, j = 0;
        for (i = k + 1; i < nums.size(); i++) {
            removeOld(tmpVec, nums[i - k - 1]);
            if (addNew(tmpVec, nums[i], t)) {
                return true;
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
//    std::vector<int> nums = {1, 5, 9, 1, 5, 9};
//    int k = 2, t = 3;
//    std::vector<int> nums = {1, 1};
//    int k = 1, t = 0;
//    std::vector<int> nums = {1, 2, 1, 1};
//    int k = 1, t = 0;
    std::vector<int> nums = {2147483646, 2147483647};
    int k = 3, t = 3;

    bool result = solve.containsNearbyAlmostDuplicate(nums, k, t);
    printf("%d\n", result);
    return 0;
}
