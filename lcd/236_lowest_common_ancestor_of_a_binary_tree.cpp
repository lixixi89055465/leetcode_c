//
// Created by nanji on 2020-11-11.
//

#include<vector>
#include "stack"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preOrder(TreeNode *node,
                  TreeNode *search,//搜索的节点
                  std::vector<TreeNode *> &path, //搜索的路径
                  std::vector<TreeNode *> &result,
                  int &finish) { //保存结果
        if (!node || finish) {
            return;
        }
        path.push_back(node);
        if (node == search) {
            finish = 1;
            result = path;
        }
        preOrder(node->left, search, path, result, finish);
        preOrder(node->right, search, path, result, finish);
        path.pop_back();
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        std::vector<TreeNode *> path;
        std::vector<TreeNode *> node_p_path;
        std::vector<TreeNode *> node_q_path;
        int finish = 0;
        preOrder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;
        preOrder(root, q, path, node_q_path, finish);
        int path_len = 0;
        if (node_p_path.size() < node_q_path.size()) {
            path_len = node_p_path.size();
        } else {
            path_len = node_q_path.size();
        }
        TreeNode *result = 0;
        for (int i = 0; i < path_len; i++) {
            if (node_p_path[i] == node_q_path[i]) {
                result = node_p_path[i];
            }
        }
        return result;
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
    b.right= &e;

    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;

    Solution solve;
    TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
    printf("lowestCommonAncestor = %d \n", result->val);
    result = solve.lowestCommonAncestor(&a, &d, &z);
    printf("lowest Common Ancestor = %d \n", result->val);
    result = solve.lowestCommonAncestor(&a, &b, &y);
    printf("lowest Common Ancestor = %d \n", result->val);

    return 0;
}


