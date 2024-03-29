//
// Created by nanji on 8/12/21.
//
#include<iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            f[i][j] = f[i - 1][j];// 左半边的子集
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}


