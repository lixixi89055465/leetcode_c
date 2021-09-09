
//
// Created by nanji on 9/2/21.
//


#include "iostream"
#include "cstdio"
#include "cstring"

using namespace std;
const int maxn = 1077;
int dp[maxn][maxn], tt;
struct T {
    int t, val;
} t[maxn * 10];

void init(int u) {
    scanf("%d%d", &t[u].t, &t[u].val);
    t[u].t *= 2;
    if (!t[u].val) init(u * 2), init(u * 2 + 1);
}

int dfs(int u, int time) {
    if (dp[u][time] > 0 || !time)
        return dp[u][time];
    if (t[u].val)
        return dp[u][time] = min(t[u].val, (time - t[u].t) / 5);
    for (int k = 0; k <= time - t[u].t; k++)
        dp[u][time] = max(dp[u][time], dfs(u << 1, k) + dfs(u << 1 | 1, time - t[u].t - k));
    return dp[u][time];
}


int main() {
    scanf("%d", &tt);
    tt--;
    init(1);
    printf("%d", dfs(1, tt));
}