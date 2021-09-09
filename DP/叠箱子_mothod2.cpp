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
这个是第二种方法，其实是第一种方法的算法优化，就改进一下状态的表示方式，设F[I，j]表示前i个箱子叠放j个箱子时可承受的最小重量即可。

即算法：
F [ i ， j ] ： = M i n F [ i − 1 ， j ] ， F [ i − 1 ， j − 1 ] + W e i g h t [ i ] F[i，j]：=Min{F[i-1，j]，F[i-1，j-1]+Weight[i] }
F[i，j]：=MinF[i−1，j]，F[i−1，j−1]+Weight[i]
A n s ： = M a x （ J ∣ F [ i ， j ] ） （ F [ i ， j ] 〈 = s u p p o r t [ i ] 〉 ） Ans：=Max（J |F[i，j] ）（F[i，j]〈=support[i]〉）
Ans：=Max（J∣F[i，j]）（F[i，j]〈=support[i]〉）
————————————————
版权声明：本文为CSDN博主「SSL_CWH」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/CWH2018/article/details/84891317 */

#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"

using namespace std;
int n, a[1005], b[1005], f[1005][1005], u = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = 2147483647 / 3;
            }
            u = 2147483647 / 3;
        }
        f[n][1] = a[n];
        for (int i = n - 1; i >= 1; i--) {
            memcpy(f[i], f[i + 1], sizeof(f[i]));//它将f[i]的数组直接复制到f[i]
            for (int j = 0; j <= n - i; j++) {
                if (f[i + 1][j] <= b[i])
                    f[i][j + 1] = min(f[i][j + 1], f[i + 1][j] + a[i]);
            }
        }
        for (int i = n; i > 0; i--) {
            if (f[1][i] != u) {
                printf("%d", i);
                break;
            }
        }
        return 0;
    }
}
