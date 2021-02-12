//
// Created by nanji on 2/12/21.
//

#include "vector"
#include "stdio.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void BST_insert(TreeNode *node, TreeNode *insert_node) {
    if (node->val > insert_node->val) {
        if (node->left) {
            BST_insert(node->left, insert_node);
        } else {
            //当左子树为空时，将node 的左指针与待插入节点相连接
            node->left = insert_node;
        }
    } else {
        // 当右子树不空的时候，递归的将insert_node 插入右子树
        if (node->right) {
            BST_insert(node->right, insert_node);
        } else {
            node->right = insert_node;
        }
    }
}

void preorder_print(TreeNode *node, int layer) {
    if (!node) {
        return;
    }
    for (int i = 0; i < layer; i++) {
        printf("---------");
    }
    printf("[%d] \n", node->val);
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}

bool BST_search(TreeNode *node, int value) {
    if (node->val == value) {// ?? 时 说明找到了
        return true;
    }
    if (node->val > value) { //?? 在左子树中查找
        if (node->left) {
            return BST_search(node->left, value);
        } else {
            return false;
        }
    } else {
        if (node->right) { //右子树不空时
            return BST_search(node->right, value);
        } else {
            return false;
        }
    }
}

////将test 中的节点，按顺序插入到二叉树中
//int main() {
//    TreeNode root(8);// 以8为根的二叉树
//    std::vector < TreeNode * > node_vec;
//    int test[] = {3, 10, 1, 6, 15};
//    for (int i = 0; i < 5; i++) {
//        node_vec.push_back(new TreeNode(test[i]));
//    }
//    for (int i = 0; i < node_vec.size(); i++) {
//        BST_insert(&root, node_vec[i]);
//    }
//    preorder_print(&root, 0);
//    return 0;
//}
int main() {
    TreeNode a(8);
    TreeNode b(3);
    TreeNode c(10);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(15);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    for (int i = 0; i < 20; i++) {
        if (BST_search(&a, i)) {
            printf("%d is in the BST . \n ", i);
        } else {
            printf("%d is not in the BST. \n", i);
        }
    }

}