//
// Created by nanji on 1/10/21.
//

#include "stdio.h"
#include "vector"
#include "queue"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BFS_print(TreeNode *root) {
    std::queue<TreeNode *> Q;
    TreeNode *node = NULL;
    Q.push(root);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        printf("\t%d", node->val);
        if (node->left) {
            Q.push(node->left);
        }
        if (node->right) {
            Q.push(node->right);
        }
    }

}

int main() {
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);

    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;

    BFS_print(&a);
    printf("\ttest");

}

