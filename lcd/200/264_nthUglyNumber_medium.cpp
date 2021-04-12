//
// Created by nanji on 4/11/21.
//
/**
 *
给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。



示例 1：

输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：

输入：n = 1
输出：1
解释：1 通常被视为丑数
 */
#include "vector"

class Solution {
public:
    int nthUglyNumber(int n) {
//        std::vector<int> dp(n + 1);
//        dp[1] = 1;
//        int p2 = 1, p3 = 1, p5 = 1;
//        for (int i = 2; i <= n; i++) {
//            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
//            dp[i] = std::min(std::min(num2, num3), num5);
//            if (dp[i] == num2) {
//                p2++;
//            }
//            if (dp[i] == num3) {
//                p3++;
//            }
//            if (dp[i] == num5) {
//                p5++;
//            }
//        }
//        return dp[n];
//        int b[] = {7, 11, 13, 14, 17, 19, 21, 22, 23, 26, 28, 29};
//        int b[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27};
        std::vector<int> vec;
        int p2 = 0, p3 = 0, p5 = 0;
        vec.push_back(1);
        for (int i = 0; i < n; i++) {
            int a2 = vec[p2] * 2, a3 = vec[p3] * 3, a5 = vec[p5] * 5;
            int min = std::min(a2, std::min(a3, a5));
            vec.push_back(min);
            if (vec[i] == a2) {
                p2++;
            } else if (vec[i] == a3) {
                p3++;
            } else if (vec[i] == a5) {
                p5++;
            }
        }

    }
};

int main() {
    Solution solve;
//    int result = solve.nthUglyNumber(10);
//    int result = solve.nthUglyNumber(1);
//    int result = solve.nthUglyNumber(17);
    int result = solve.nthUglyNumber(20);
    printf("result:%d\n", result);
    return 0;
}
