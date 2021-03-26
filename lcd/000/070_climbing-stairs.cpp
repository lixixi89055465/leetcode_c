//
// Created by nanji on 2/27/21.
//
#include "vector"

class Solution {
public:
    int climbStairs2(int n) {
        std::vector<int> dp(n + 3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs1(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }
};
int main(){
    Solution solve;
    printf("%d\n",solve.climbStairs2(3));
    return 0;
}

