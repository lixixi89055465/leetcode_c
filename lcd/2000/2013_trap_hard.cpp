//
// Created by nanji on 4/2/21.
/**
 * 给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
 */
//

#include "vector"
#include "queue"

class Solution {
public:
    int trap(std::vector<int> &height) {
        if (height.size() < 3) {
            return 0;
        }
        int i = 0, left = 0, right = height.size() - 1, result = 0;
        while (left < right - 1) {
            if (height[left] < height[right]) {
                if (height[left] > height[left + 1]) {
                    result += height[left] - height[left + 1];
                    height[left + 1] = height[left];
                }
                left++;
            } else {
                if (height[right] > height[right - 1]) {
                    result += height[right] - height[right - 1];
                    height[right - 1] = height[right];
                }
                right--;
            }
        }
        return result;
    }
};

int main() {
    Solution solve;
    std::vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solve.trap(vec);
    printf("%d\n", result);
    return 0;
}