//
// Created by nanji on 1/10/21.
//

#include "stdio.h"
#include "vector"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root, std::vector<TreeNode *> &nodeList) {
        if (!root) {
            return;
        }
        nodeList.push_back(root);
        flatten(root->left, nodeList);
        flatten(root->right, nodeList);
    }
};

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

    Solution solve;
    std::vector<TreeNode *> nodeList;
    printf("test");
    solve.flatten(&a, nodeList);
    for (int i = 0; i < nodeList.size(); i++) {
        printf("%d\t", nodeList[i]->val);
    }
    printf("\n");
    printf("fsdlaf");
    return 0;
}
