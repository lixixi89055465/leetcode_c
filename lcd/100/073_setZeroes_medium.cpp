//
// Created by nanji on 3/21/21.
//
/**
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？


 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include "vector"
#include "set"

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        std::vector<std::pair<int, int>> zeroArr;
        std::set<int> seti, setj;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (!matrix[i][j]) {
                    seti.insert(i);
                    setj.insert(j);
                }
            }
        }
        for (std::set<int>::iterator it = seti.begin(); it != seti.end(); it++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[*it][j] = 0;
            }
        }
        for (std::set<int>::iterator it = setj.begin(); it != setj.end(); it++) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][*it] = 0;
            }
        }
    }
};

void printMatrix(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
//    输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
//    输出：[[1,0,1],[0,0,0],[1,0,1]]
    std::vector<std::vector<int>> matrix = {{1, 1, 1},
                                            {1, 0, 1},
                                            {1, 1, 1}
    };
    Solution solve;
    printMatrix(matrix);
    solve.setZeroes(matrix);
    printf("\n");
    printMatrix(matrix);
    return 0;
}