//
// Created by nanji on 9/11/21.
//

/**
 * 题目描述
现在要把m本有顺序的书分给k给人复制（抄写），每一个人的抄写速度都一样，一本书不允许给两个（或以上）的人抄写，分给每一个人的书，必须是连续的，比如不能把第一、第三、第四本书给同一个人抄写。

现在请你设计一种方案，使得复制时间最短。复制时间为抄写页数最多的人用去的时间。
 */

#include "iostream"

using namespace std;

int fun1(int m, int k, int *nums) {
    int dp[100][100];
    int s[100];
    memset(dp, 127, sizeof(dp));
    memset(s, 0, sizeof(s));
    int numM = 0;
    for (int i = 1; i <= m; i++) {
        s[i] = nums[i - 1] + s[i - 1];
        dp[1][i] = s[i];
        if (nums[i] > numM) {
            numM = nums[i];
        }
        dp[i][i] = numM;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <=m ; j++) {
            for (int c = i+1 ; c <= j ; c++) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][c], s[j] - s[c]));
            }
        }
    }
    cout << dp[k][m] << endl;
    return dp[k][m];
}


int main() {
    int m = 9, k = 3;
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = fun1(m, k, nums);
    cout << result << endl;
    return 0;
}
