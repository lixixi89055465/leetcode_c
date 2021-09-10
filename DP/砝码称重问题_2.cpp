//
// Created by nanji on 9/10/21.
//
/**
 * 砝码称重问题
　　砝码称重问题:设有1g、2g、3g、5g、10g、20g的砝码各若干枚（其质量<=1000g），求出用他们能称出的质量的种类数(不包括质量为0的情况)。

　　一、动态规划方法求解

　　设dp[1000]数组为标记数组。当dp[i]=0时，表示质量为i的情况，目前没有称出；当dp[i]=1时，表示质量为i的情况已经称出。

　　本题目中有多个砝码，我们顺序处理每一个砝码。

　　当处理第j个砝码，质量为wj时，有下列推导公式：
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int fama(int N, int weight[], int num[])
{
    int AllWeight = 0, i, j;
    for (i = 0; i < N; i++)
        AllWeight = AllWeight + weight[i] * num[i];
    int flag[100000] = {0};

    /*先计算第0种砝码能够得到的称重数量，并且计算第0种砝码最大的重量*/
    int TempWeight = 0;
    for (i = 0; i <=num[0]; i++)
    {
        flag[weight[0] * i] = 1;
    }
    TempWeight = weight[0]*num[0];
    //从此以后TempWeight将用来表示前一种砝码的最大重量

    i = 1;//从第1种砝码开始做
    int CurrentWeight;
    int NewWeight;
    while (i < N)
    {
        for (j = 1; j <=num[i]; j++)//第i种砝码的个数最多为num[i]
        {
            for (CurrentWeight = 0; CurrentWeight <=TempWeight; CurrentWeight++)//CurrentWeight采用试探的方式逐次加1它的大小不能大于前一种重量的最大值
            {
                NewWeight = CurrentWeight + j*weight[i];
                if (NewWeight>AllWeight) break;
                if (flag[CurrentWeight==1]&&flag[NewWeight]==0)//如果当前的这个重量可以由前一种砝码和当前砝码组合而成
                {
                    flag[NewWeight] = 1;
                }
            }
        }
        TempWeight = TempWeight + num[i] * weight[i];//更新上一个砝码的最大重量
        i++;
    }

    /*统计总数量*/
    int count = 0;
    for (i = 0; i < 1000; i++) { if (flag[i] == 1) count++; }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int *w = new int[n];
    int *num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> num[i];

    cout <<fama(n,w,num)<<endl;
    return 0;
}