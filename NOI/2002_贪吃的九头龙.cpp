//
// Created by nanji on 8/30/21.
//

#include "cstdio"
#include "cstring"
#include "stdio.h"

using namespace std;
#define N 305
struct node {
    int v, w, next;
} e[N << 1];
int tot, head[N << 1];
int n, m, k;
int sum[N], tmp[N][2], f[N][N][2];

inline void MIN(int &x, int y, int z) {
    if (x > y)x = y;
    if (x > z)x = z;
}

inline void add(int x, int y, int z) {
    e[++tot].v = y;
    e[tot].w = z;
    e[tot].next = head[x];
    head[x] = tot;
}

void dp(int x, int from) {
    f[x][1][1] = f[x][0][0] = 0;
    sum[x] = 1;
    int i, j, k, y, t;
    for (i = head[x]; i; i = e[i].next) {
        if ((y = e[i].v) != from) {
            dp(y, x);
            sum[x] += sum[y];
            t = (m == 2 ? e[i].w : 0);
            memcpy(tmp, f[x], sizeof(f[x]));
            memset(f[x], 127 / 3, sizeof(f[x]));
            for (j = sum[x]; j + 1; j--) {
                if (j) {
                    for (k = j - 1; k + 1; k--) {
                        MIN(f[x][j][1], tmp[j - k][1] + f[y][k][0], tmp[j - k][1] + f[y][k][1]);
                    }
                    for (k = j; k + 1; j--) {
                        MIN(f[x][j][0], tmp[j - k][0] + f[y][k][0] + t, tmp[j - k][0] + f[y][k][1]);
                    }

                }
            }
        }
    }
}

int main() {
    memset(f, 127 / 3, sizeof f);
    scanf('%d%d%d', &n, &m, &k);
    if (n - k < m - 1) {
        puts("-1");
        return 0;
    }
    for (int i = 1, x, y, z; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    dp(1, 0);
    printf("%d\n", f[1][k][1]);
    return 0;
}
