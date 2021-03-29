//
// Created by nanji on 3/28/21.
//

/**
 * 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。

你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search-tree-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


#include "stdio.h"
#include "stack"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    std::stack<TreeNode *> s;

public:
    BSTIterator(TreeNode *root) {
        TreeNode *tmp = root;
        while (!s.empty() || tmp) {
            if (tmp) {
                s.push(tmp);
                tmp = tmp->left;
            } else {
                tmp = s.top();
                s.pop();
                tmp = tmp->right;
            }
        }
        tmp = root;
        while (tmp) {
            s.push(tmp);
            tmp = tmp->left;
        }
    }

    int next() {
        if (s.empty()) {
            return -1;
        }
        TreeNode *tmp = s.top();
        int value = tmp->val;
        if (s.top()->right) {
            s.push(s.top()->right);
            while (s.top()->left) {
                s.push(s.top()->left);
            }
        } else {
            s.pop();
            while (!s.empty() && tmp == s.top()->right) {
                tmp = s.top();
                s.pop();
            }
        }
        return value;
    }

    bool hasNext() {
        return !s.empty();
    }
};

int main() {
    TreeNode a(7), b(3), c(15), d(9), e(20);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    b.left = b.right = d.left = d.right = e.left = e.right = NULL;
    BSTIterator solve(&a);
    printf("%d\n", solve.next());
    printf("%d\n", solve.next());
    printf("%d\n", solve.hasNext());
    printf("%d\n", solve.next());
    printf("%d\n", solve.hasNext());
    printf("%d\n", solve.next());
    printf("%d\n", solve.hasNext());
    printf("%d\n", solve.next());
    printf("%d\n", solve.hasNext());
    return 0;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */