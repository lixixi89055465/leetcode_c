/*
 *给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。


 示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "vector"
#include "set"

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> vec;
        std::vector<int> tmp;
        vec.push_back(tmp);
        int i = 0, j = 0, n = 0, lastN = 0;
        for (i = 0; i < nums.size(); i++) {
            n = vec.size();
            if (i==0||nums[i] != nums[i - 1]) {
                for (j = 0; j < n; j++) {
                    tmp = vec[j];
                    tmp.push_back(nums[i]);
                    vec.push_back(tmp);
                }
            } else {
                for (j = lastN; j < n; j++) {
                    tmp = vec[j];
                    tmp.push_back(nums[i]);
                    vec.push_back(tmp);
                }
            }
            lastN = n;
        }
        return vec;
    }
};

int main() {
    Solution solve;
    std::vector<int> nums = {1, 1, 2, 2, 3};
//    std::vector<int> nums = {1, 2, 2};
    std::vector<std::vector<int>> vec = solve.subsetsWithDup(nums);
    printf("%d\n", vec.size());
    return 0;
}