//
// Created by nanji on 2/13/21.
//

#include "stdio.h"
#include "vector"

struct BSTNode {
    int val;
    int count;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int x) : val(x), left(NULL), right(NULL), count(0) {}
};


void BST_insert(BSTNode *node, BSTNode *insert_node, int &count_small) {
    if (node->val > insert_node->val) {// count_samll 二叉排序树中比。insert_node 值小的节点个数
        node->count++;
        if (node->left) {
            BST_insert(node->left, insert_node, count_small);
        } else {
            node->left = insert_node;
        }
    } else {
        count_small = count_small + node->count + 1;
        if (node->right) {
            BST_insert(node->right, insert_node, count_small);
        } else {
            node->right = insert_node;
        }
    }
}

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int> &nums) {
        std::vector<int> result; // 最终逆序数组
        std::vector<BSTNode *> node_vec; //创建的二叉查找树节点池
        std::vector<int> count; //从后向前插入过程中，比当前节点值小的
        for (int i = nums.size() - 1; i >= 0; i--) {
            node_vec.push_back(new BSTNode(nums[i]));
            //按照从后向前的顺序创建二叉查找树节点 。
        }
        count.push_back(0); //第一个节点count_samll=0
        for (int i = 1; i < node_vec.size(); i++) {
            int count_small = 0;
            BST_insert(node_vec[0], node_vec[i], count_small);
            count.push_back(count_small);
        }
        for (int i = node_vec.size() - 1; i >= 0; i--) {
            delete node_vec[i];
            result.push_back(count[i]);
        }
        return result; //最终返回result
    }
};

int main() {

}
