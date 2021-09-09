//
// Created by nanji on 8/31/21.
/**
 * 皇宫看守【题解】

红领巾Zzz 2019-05-14 15:10:54  1002  收藏 4
分类专栏： 题解 文章标签： 树型DP
版权

题解
专栏收录该内容
10 篇文章0 订阅
订阅专栏
题目链接：https://loj.ac/problem/10157

题目分析
根据题意对当前结点x进行分类讨论，可以得出以下三种情况：
情况1，当前结点x可以被父节点看到
情况2，当前结点x可以被子节点看到
情况3，当前结点安排守卫看守。

因此我们可以得到当前状态需要保存三个值。
设
F(x,0)为x结点被父节点看到
F(x,1)为x结点被子节点看到
F(x,2)为在x结点上安排守卫


对于情况1
当前结点x可以被父节点看到。
意味着x的子结点y要么安排警卫，要么子结点y可以被它的子结点看到
F(x,0)=∑( min{ F(y,1),F(y,2) })


对于情况2
当前结点x被子节点看到，子结点y至少有一个结点需要安排看守。

理想的情况下，子结点y中如果有至少有一个结点满足min{F(y,1),F(y,2) }的结果为F(y,2)
可得：F(x,1)=∑( min{ F(y,1),F(y,2) })

但是如果所有的子结点y都是F(y,1)更小，那么至少要取一个子结点的F(y,2).
解决的方法是取{F(y,1),F(y,2)}绝对值最小一组的F(y,2),可使总和最小

例

F(y,1)	6	3	1
F(y,2)	7	5	4
Res 1=7+3+1=11
Res 2=6+5+1=12
Res 3=6+3+4=13
显然取abs更小的F(y,2)更优

数学证明：
(a1-b1)<(a2-b2)
a1+b2<a2+b1

状态转移方程为：F(x,0)=∑( min{ F(y,1),F(y,2) })+min{ F(y,2)-min{ F(y,1),F(y,2)}}


对于情况3
当前结点x安排了警卫，那么x的子结点y可以安排警卫，也可以被y的儿子看守，还可以被它的父亲看守。
可得状态方程：
F(x,2)=∑( min{ F(y,0),F(y,1),F(y,2) } )+a[x]
注：a[x]为当前结点安排的警卫数量


总结
树型动态规划有一个共性，那就是它的基本模型都是一棵树或者森林。
在分析阶段，我们要对根据题意分类讨论，得到当前结点需要保存哪些状态，在不同状态下，与子结点的状态有什么联系，也就是如何由子结点的最优解得到当前结点的最优解。

在看参考代码之前，同学们可以根据上述思路先自己编写代码，自己写不出来了再看代码。
可按照下面步骤写代码：
1.使用邻接表保存树。
2.对树进行遍历，遍历的过程中，递归求解每个结点的状态值。
3.输出答案


————————————————
版权声明：本文为CSDN博主「红领巾Zzz」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Zerotogether/article/details/90206682
 */

#include <cstdio>
#include <iostream>
using namespace std;
struct edge {
    int next, to;
} tree[500050];
int n, f[500050][3], w[500050], root, pd[500050], num, head[500050];
void addedge(int u, int v) {
    tree[++num] = (edge){ head[u], v };
    head[u] = num;
}
void dfs(int u) {
    int d = 9999999;
    for (int i = head[u]; i; i = tree[i].next) {
        int y = tree[i].to;
        dfs(y);
        f[u][0] += min(f[y][2], f[y][1]);
        f[u][1] += min(f[y][2], f[y][1]);
        d = min(d, f[y][2] - min(f[y][2], f[y][1]));
        f[u][2] += min(f[y][2], min(f[y][1], f[y][0]));
    }
    f[u][1] += d;
    f[u][2] += w[u];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v, k;
        scanf("%d%d%d", &v, &k, &u);
        w[v] = k;
        for (int j = 1; j <= u; j++) {
            int x;
            scanf("%d", &x);
            pd[x] = 1;
            addedge(v, x);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!pd[i]) {
            root = i;
            break;
        }
    dfs(root);
    cout << min(f[root][1], f[root][2]);
    return 0;
}
