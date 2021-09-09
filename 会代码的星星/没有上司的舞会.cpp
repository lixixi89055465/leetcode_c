//
// Created by nanji on 8/19/21.
//
#include "iostream"
#include "vector"

using namespace std;
const int N = 6010;

int ha[N], fa[N];
int dp[N][2];
vector<int> v[N]; //保存当前节点的子节点

int n;

void dfs(int u) {
    if (u == 0)return;
    for (int i = 0; i < v[u].size(); ++i) {
        int son = v[u][i];
        dp[u][1] = ha[u];
        dfs(son);
        dp[u][0] += max(dp[son][1], dp[son][0]);
        dp[u][1] += dp[son][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) cin >> ha[i];
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        fa[x] = y;
        v[y].push_back(x); //把自节点push 到父节点的尾部
    }
    int root = 1;
    while (fa[root] != root) {
        root = fa[root];
    }
    dfs(root);
    int ans = max(dp[root][0], dp[root][1]);
    cout << ans;
    return 0;
}
