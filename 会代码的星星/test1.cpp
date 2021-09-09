//
// Created by nanji on 8/30/21.
//

#include "iostream"
#include "cstring"

using namespace std;
const int N = 110, M = 2 * N;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int f[N][N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int parent) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if (v == parent) {
            continue;
        }
        dfs(v, u);
        //枚举树枝总数的上界（即保留不超过多少个树枝
        for (int j = m; j >= 1; j--) {
            //枚举v这颗子树取多少个树枝
            for (int k = 0; k < j; k++) {
                f[u][j] = max(f[u][j], f[u][j - k - 1] + w[i]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //只知道树根但不知道边的方向,所以只能取双边
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << f[1][m] << endl;
    return 0;
}