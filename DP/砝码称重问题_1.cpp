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



#include<stdio.h>
#include<string.h>

int sum;  ///表示输入的砝码的总质量
int ma[6];  ///六种砝码的个数
int weight[6] = {1, 2, 3, 5, 10, 20};  ///六种砝码的重量
char dp[1001]; ///标记位

void input();   ///输入每个砝码的数量，并求出所有砝码的总质量sum
void exeDP();

void output();  ///判断标记为1的数量，并输出

int main() {
    memset(dp, 0, sizeof(dp));
    input();
    exeDP();
    output();
    return 0;
}

void input() {
    int i;
    sum = 0;
    for (i = 0; i < 6; i++) {
        scanf("%d", &ma[i]);
        sum = sum + (ma[i] * weight[i]);
    }
}

void exeDP() {
    int i, j, z;
    dp[0] = 1;
    for (i = 0; i < 6; i++)    ///六种砝码
    {
        for (j = 0; j < ma[i]; j++)    ///每种砝码的个数
        {
            for (z = sum; z >= weight[i]; z--) ///判断每种质量是否可以被称出
            {
                if (dp[z - weight[i]] == 1)
                    dp[z] = 1;
            }
        }
    }
}

void output() {
    int i, time = 0;
    for (i = 1; i <= sum; i++) {
        if (dp[i] == 1)    ///若能被称出，则计数
            time++;
    }
    printf("%d", time);
}