//
// Created by nanji on 2/12/21.
//

#include "vector"
#include "stdio.h"
#include "string"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


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

void collect_nodes(TreeNode *node, std::vector<TreeNode *> &node_vec) {
    if (!node) {
        return;
    }
    node_vec.push_back(node);
    collect_nodes(node->left, node_vec);
    collect_nodes(node->right, node_vec);
}

void change_int_to_string(int val, std::string &str_val) {
    std::string tmp;
    while (val) {//遍历val,每次将val 的最低位转换为 字符，添加到tmp的尾部
        tmp += val % 10 + '0';
        val = val / 10;
    }
    for (int i = tmp.length() - 1; i >= 0; i--) {
        str_val += tmp[i]; //逆序将字符串添加到str_val 中
    }
    str_val += '#';
}

void BST_preorder(TreeNode *node, std::string &data) {
    if (!node) {
        return;
    }
    std::string str_val;
    change_int_to_string(node->val, str_val);
    data += str_val;
    BST_preorder(node->left, data);
    BST_preorder(node->right, data);
}


class Codec {
public:
    std::string serialize(TreeNode *root) {
        std::string data;
        BST_preorder(root, data);// 将 root 指向的树转为 字符串 data
        return data;
    }

    TreeNode *deserialize(std::string data) {
        if (data.length() == 0) {
            return NULL;
        }
        std::vector<TreeNode *> node_vec;
        int val = 0;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '#') {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            } else {
                val = val * 10 + data[i] - '0';
            }
        }
        for (int i = 1; i < node_vec.size(); i++) {
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
};
int main(){
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
    Codec solve;
    std::string data=solve.serialize(&a);
    printf("%s \n",data.c_str());
    TreeNode*root=solve.deserialize(data);
    preorder_print(root,0);
    return 0;
}



//
//int main() {
//    std::string str = "123#456#10000#1#";
//    int val = 0;
//    for (int i = 0; i < str.length(); i++) {
//        if (str[i] == '#') {
//            printf("val = %d \n ", val);
//            val = 0;
//        } else {
//            val = val * 10 + str[i] - '0';
//        }
//    }
//    return 0;
//}