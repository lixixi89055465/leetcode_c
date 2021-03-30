//
// Created by nanji on 3/30/21.
//
/**
 *
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "vector"

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int left = 0, right = matrix.size() - 1, mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (target < matrix[mid][0]) {
                right = mid - 1;
            } else if (target > matrix[mid][matrix[0].size() - 1]) {
                left = mid + 1;
            } else {
                break;
            }
        }
        printf("left is  %d right is %d  : ", left, right);
        int index = left;
        left = 0, right = matrix[0].size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target < matrix[index][mid]) {
                right = mid - 1;
            } else if (target > matrix[index][mid]) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{1,  3,  5,  7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 60}};
    Solution solve;
    printf("%d\n", solve.searchMatrix(matrix, 13));
    return 0;
}