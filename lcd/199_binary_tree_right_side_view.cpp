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

    std::vector<int> rightSideView1(TreeNode *root) {
        std::vector<int> view; //按层遍历的最后一个节点
        std::queue<std::pair<TreeNode *, int >> Q; //宽度优先搜索队列<节点,层数>
        if (root) {
            Q.push(std::make_pair(root, 0)); //根节点非空时，将<root,0>push进入队列
        }
        while (!Q.empty()) {
            TreeNode *node = Q.front().first;//搜索节点
            int depth = Q.front().second; //待搜索节点的层数
            Q.pop();
            if (view.size() == depth) {
                view.push_back(node->val);
            } else {
                view[depth] = node->val;
            }
            if (node->left) {
                Q.push(std::make_pair(node->left, depth + 1));
            }
            if (node->right) {
                Q.push(std::make_pair(node->right, depth + 1));
            }

        }
        return view;


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

