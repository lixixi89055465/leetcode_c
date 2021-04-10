/*
 *
 * 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。
输入：n = 6
输出：true
解释：6 = 2 × 3
示例 2：

输入：n = 8
输出：true
解释：8 = 2 × 2 × 2
示例 3：

输入：n = 14
输出：false
解释：14 不是丑数，因为它包含了另外一个质因数 7 。
示例 4：

输入：n = 1
输出：true
解释：1 通常被视为丑数。

 */
#include "stdio.h"

class Solution {
public:
    bool isUgly(int n) {
        while (n != 0 && n != 1) {
            if (!(n % 2)) {
                n /= 2;
            } else if (!(n % 3)) {
                n /= 3;
            } else if (!(n % 5)) {
                n /= 5;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solve;
    int n = -2147483648;
    int result = solve.isUgly(n);
    printf("%d\n", result);
    return 0;
}