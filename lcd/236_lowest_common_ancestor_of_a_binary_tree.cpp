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

    void lowest_common_ancestor_of_a_binary_tree1(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *jiao) {
        std::vector<TreeNode *> pathP, resultP;
        std::vector<TreeNode *> pathQ, resultQ;

        int finishP = 0;
        int finishQ = 0;
        preOrder(root, p, pathP, resultP, finishP);
        preOrder(root, q, pathQ, resultQ, finishQ);
        while (resultP.front() == resultQ.front()) {
            jiao = resultP.front();
            resultP.pop_back();
            resultQ.pop_back();
        }

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


