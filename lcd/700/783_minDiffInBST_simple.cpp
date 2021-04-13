//
// Created by nanji on 4/13/21.
/**
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
输入：root = [4,2,6,1,3]
输出：1
输入：root = [1,0,48,null,null,12,49]
输出：1
 */
#include "stdio.h"
#include "math.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Ele {
    int min;
    int max;
    int val;

    Ele() : val(-1), min(0), max(0) {};

    Ele(int x) : val(x), min(0), max(0) {};
};

const int max = 1000000;

class Solution {
public:
    Ele minDst(TreeNode *root) {
        Ele leftE, rightE, e;

        if (root->left && !root->right) {
            leftE = minDst(root->left);
            e.min = leftE.min;
            e.max = root->val;
            e.val = root->val - leftE.max;
            e.val = e.val < leftE.val ? e.val : leftE.val;
        } else if (root->right && !root->left) {
            rightE = minDst(root->right);
            e.min = root->val;
            e.max = rightE.max;
            e.val = rightE.min - root->val;
            e.val = e.val < rightE.val ? e.val : rightE.val;
        } else if (root->right && root->left) {
            leftE = minDst(root->left);
            rightE = minDst(root->right);
            e.min = leftE.min;
            e.max = rightE.max;
            e.val = (root->val - leftE.max) < (rightE.min - root->val) ? (root->val - leftE.max) : (rightE.min -
                                                                                                    root->val);
            int tmp1 = leftE.val < rightE.val ? leftE.val : rightE.val;
            e.val = e.val < tmp1 ? e.val : tmp1;
        } else {
            e.min = root->val;
            e.max = root->val;
            e.val = max;
        }
        return e;
    }

    int minDiffInBST(TreeNode *root) {
        Ele e = minDst(root);
        return e.val;
    }
};

int main() {
//    [4,2,6,1,3]
//    [27,null,34,null,58,50,null,44]
//    TreeNode n1(4), n2(2), n3(6), n4(1), n5(3);
//    TreeNode n1(27), n2(34), n3(58), n4(50), n5(44);
    TreeNode n1(1), n2(48), n3(12), n4(49);
    n1.right = &n2;
    n2.left= &n3;
    n2.right= &n4;
    Solution solve;
    int result = solve.minDiffInBST(&n1);
    printf("result is %d\n", result);
    return 0;
}