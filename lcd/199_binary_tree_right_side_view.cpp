//
// Created by nanji on 1/10/21.
//

#include "queue"
#include "vector"
#include "stdio.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode *root) {
        std::queue<TreeNode *> Q;
        std::vector<int> nodeList;
        TreeNode *node;

        Q.push(root);
        int num = Q.size();
        while (!Q.empty()) {
            node = Q.front();
            Q.pop();
            num--;
            if (node->left) {
                Q.push(node->left);
            }
            if (node->right) {
                Q.push(node->right);
            }
            if (num == 0) {
                num = Q.size();
                nodeList.push_back(node->val);
            }
        }
        return nodeList;
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
    printf("test");


    std::vector<int> nodeList = solve.rightSideView(&a);
    for (int i = 0; i < nodeList.size(); i++) {
        printf("\t%d", nodeList[i]);
    }
    printf("\n");
    return 0;
}

