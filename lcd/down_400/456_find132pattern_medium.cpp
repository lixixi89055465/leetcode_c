//
// Created by nanji on 3/24/21.
//
/**
 * 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

注意：n 的值小于15000。

示例1:

输入: [1, 2, 3, 4]

输出: False

解释: 序列中不存在132模式的子序列。
示例 2:

输入: [3, 1, 4, 2]

输出: True

解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
示例 3:

输入: [-1, 3, 2, 0]

输出: True

解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include "vector"

int findMax(std::vector<int> &nums, int start, int end) {
    int max = nums[start];
    for (int i = start + 1; i <= end; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }

    return max;
}

class Solution {
public:
    bool find132pattern(std::vector<int> &nums) {
        if(nums.size()<3){
            return false;
        }
        int i, j, k;
        for (i = 0; i < nums.size() - 2; i++) {
            if (nums[i] >= nums[i + 1]) {
                continue;
            }
            for (j = i + 1; j < nums.size() - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    break;
                }
            }
            for (k = j + 1; k < nums.size(); k++) {
                if (nums[k] < nums[j] && nums[k] > nums[i]) {
                    return true;
                }
            }
            i = j;
        }
        return false;
    }
};


int main() {
    std::vector<int> vec = {-1, 3, 2, 0};
    Solution solve;
    bool result = solve.find132pattern(vec);
    printf("%d\n", result);
    printf("%d", vec.size());
    return 0;
}
