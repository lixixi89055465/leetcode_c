//
// Created by nanji on 9/6/21.
//
/**
 * 采用动态规划解决最佳加法表达式比较容易，难点在于高精度计算，本文前部分给出了解决该问题的基本方法，转载了高精度方法。

一、题目描述

描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1

输出
对每组数据，输出最小加法表达式的值

样例输入
2
123456
1
123456
4
12345

样例输出
102
579
15

提示
 二、问题分析

将m个加号插入到n个数中，求能得到的最小表达式结果。可以先考虑把最后一个加号插入到某个数之后，该数一定在m到n-1之间，因为剩余m-1个加号至少需要m个数来放置，所以最后一个加号的位置必然在m之后，毫无疑问最后一个加号最多放在倒数第二个数（n-1）之后。

将最后一个加号放到第k个数之后形成的表达式值由两部分组成：
（1）前m-1个加号放到前k个数中形成得到的表达式值 minVal(m-1,k)
（2）第k+1字符到最后一个字符组成的数值，Num（k+1，n）
没有加号时，结果只由第二部分组成

所以

最小加法表达式   minVal(m,n) = Min{ minVal(m-1,k) + Num(k+1,n) } ( k = m … n-1)
 */

#include "iostream"
#include "string"
#include "cstring"
#include "algorithm"

using namespace std;

int main() {
    int m = 0;
    int n = 0;
    string numLine;//输入的数字序列
    int Num[50][50];//Num[i][j]表示numLine 序列第i个到第j个数字连接成的数的值
    while (cin >> m) {
        cin >> numLine;
        n = numLine.length();
        for (int i = 1; i <= n; i++) {//将第i,j间的连接字符序列转变为一个数值3
            Num[i][i] = numLine[i - 1] - '0';
            for (int j = i + 1; j <= n; j++) {
                //numLine 的下标从0开始，第j个字符的下标为j-1
                Num[i][j] = Num[i][j - 1] * 10 + numLine[j - 1] - '0';
            }
        }
        int **minVal = 0;
        memset(minVal, 0x3f, sizeof(minVal));
        for (int i = 1; i <= m; i++) {//i个加号
            for (int j = i; j <= n; j++) {//j个数字，数字个数不能少于加号个数
                //需要取j=i,不然算不对
                minVal[0][j] = Num[1][j];//没有加号的情形
                for (int k = i; k < j; k++) {
                    minVal[i][j] = min(minVal[i][j], minVal[i - 1][k] + Num[k + 1][j]);
                }

            }

        }
    }
}


