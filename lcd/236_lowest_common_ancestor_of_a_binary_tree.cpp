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
                  TreeNode *search,
                  std::vector<TreeNode *> &path,//遍历时的节点路径栈
                  std::vector<TreeNode *> &result,//最终搜索到节点search 的路径结果
                  int &finish) {
        if (!node || finish) {
            return;
        }
        path.push_back(node);
        if (node == search) {
            finish = 1;

        }
        preOrder(node->left, search, path, result, finish);
        preOrder(node->right, search, path, result, finish);
        path.pop_back();

    }

    void lowest_common_ancestor_of_a_binary_tree() {

    }

};


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
    return 0;
}


