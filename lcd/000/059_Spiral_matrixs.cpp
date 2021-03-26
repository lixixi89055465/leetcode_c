//
// Created by nanji on 2/19/21.
//

#include "string"
#include "vector"

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        int left = 0, up = 0, right = n - 1, down = n - 1;
        int count = 1;
        std::vector<std::vector<int>> matrix;
        for (int i = 0; i < n; i++) {
            std::vector<int> a;
            for (int j = 0; j < n; j++) {
                a.push_back(0);
            }
            matrix.push_back(a);
        }
        for (int a = n; a > 0; a -= 2) {
            for (int i = left; i <= right; i++) {
                matrix[up][i] = count++;
            }
            up++;
            for (int i = up; i <= down; i++) {
                matrix[i][right] = count++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                matrix[down][i] = count++;
            }
            down--;
            for (int i = down; i >= up; i--) {
                matrix[i][left] = count++;
            }
            left++;
        }
        return matrix;

    }
};

int main() {
    int n = 5;
    Solution solve;
    std::vector<std::vector<int>> matrix = solve.generateMatrix(n);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("\t%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}