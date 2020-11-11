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
    void preorder(TreeNode *node, //
                  int &path_value, //
                  int sum, //
                  std::vector<int> &path, //
                  std::vector<std::vector<int>> &result) {
        if (!node) {
            return;
        }
        path_value += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && path_value == sum) {
            result.push_back(path);
        }
        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);
        path_value -= node->val;
    }

    void houorder(TreeNode *node, int &sum) {
        if (!node) {
            return;
        }
        sum += node->val;
        houorder(node->left, sum);
        houorder(node->right, sum);
        if (!node->left && !node->right) {
            printf("sum:%d", sum);
        }
        sum -= node->val;
    }

    void prePathSum(TreeNode *root, int &sum) {
        std::vector<TreeNode *> stack;
        TreeNode *node = root;
        while (!stack.empty() || node) {
            while (node) {
                sum += node->val;
                stack.push_back(node);
                node = node->left;
            }
            if (!stack.empty()) {
                node = stack.back();
                printf("node->data:%d\n", node->val);
                stack.pop_back();
                sum -= node->val;
                node = node->right;
            }
        }
    }
};

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
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode i(5);
    TreeNode j(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;

    f.left = &i;
    f.right = &j;

//    preorder_print(&a, 0);
//    preorder_print(&a, 0);
    Solution solve;
    int sum = 0;
    solve.houorder(&a, sum);
    return 0;
}


