//
// Created by nanji on 2020-11-04.
//

#include "stdio.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal_print3(TreeNode *node, int layer) {
    if (!node) {
        return;
    }
    for (int i = 0; i < layer; i++) {
        printf("-------");
    }
    printf("[%d]\n", node->val);
    traversal_print3(node->left, layer + 1);
    traversal_print3(node->right, layer + 1);
}

void traversal_print2(TreeNode *node, int layer) {
    if (!node) {
        return;
    }
    traversal_print2(node->left, layer + 1);
    traversal_print2(node->right, layer + 1);
    for (int i = 0; i < layer; i++) {
        printf("-------");
    }
    printf("[%d]\n", node->val);
}


void traversal_print1(TreeNode *node, int layer) {
    if (!node) {
        return;
    }
    traversal_print1(node->left, layer + 1);
    for (int i = 0; i < layer; i++) {
        printf("-------");
    }
    printf("[%d]\n", node->val);
    traversal_print1(node->right, layer + 1);
}

void preorder_print(TreeNode *node, int layer) {
    if (!node) {
        return;
    }
    for (int i = 0; i < layer; i++) {
        printf("-------");//根据层数，打印相应的数量的'-'
    }
    printf("[%d] \n", node->val);
    preorder_print(node->left, layer + 1);//遍历左子树，层数+1
    preorder_print(node->right, layer + 1);//遍历右子树，层数+1
}

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.right = &f;
    preorder_print(&a, 0);
    return 0;
}
