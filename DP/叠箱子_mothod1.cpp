//
// Created by nanji on 9/4/21.
//
/**
 * 题目
某港口有一批集装箱，将其编号，分别为1至N。每一个箱子的外型尺寸都是一样的，现在要将其中某些集装箱叠放起来，集装箱叠放的规则如下：
　　1)每个集装箱上最多只能直接叠放一个集装箱。
　　2)编号较小的集装箱不能放在编号较大的集装箱之上。
　　3)每个集装箱都给出了自身的重量和可承受的重量，每个集装箱之上的所有集装箱重量之和不得超过该集装箱的可承受的重量。

现在要求你编程，从中选出最多个集装箱，使之在满足以上条件的情况下叠放起来，即要求叠得尽可能地高。

输入
第一行是一个正整数N，表示共有N个集装箱（1≤ N ≤1000）。
　　以下共有N行，每行两个正整数，中间用空格分隔，分别表示每个集装箱的自身重量和可承受的重量，两个数均为小于等于3000。

输出
输出最多可叠放的集装箱总数。运行时间不超过去时10秒。

输入样例
5
19 15
7 13
5 7
6 8
1 2

输出样例
４

解题思路
先要想，因为它是要求最多可叠放的集装箱总数，那可以是从上到下的去找它最适合的箱子，但也要考虑箱子的自生重量和承受重量。

注意
for循环要循环到6000，因为一个箱子上肯定有箱子的，所以箱子最大的重量和承受的重量是要相加
 */

#include "iostream"
#include "cstdio"

using namespace std;
int n, a[1002], b[1002], f[1002][6002], ans = 0;

int main() {
    memset(f, -127 / 3, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        f[n + 1][0] = 0;//在最顶上设0来做边界
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j <= 6000; j++) {
                f[i][j] = f[i + 1][j];//来把下一个箱子列举一下
                if (j >= a[i] && b[i] >= j - a[i])//来判断自生成重量和承受重量有没有超限
                    f[i][j] = max(f[i][j], f[i + 1][j - a[i]] + 1);//找最多可叠放的集装箱总数
            }
        }
        for (int i = 0; i <= 6000; i++) {
            ans = max(ans, f[1][i]);//最后再选一次最大值
            printf("%d", ans);
        }

    }
}

