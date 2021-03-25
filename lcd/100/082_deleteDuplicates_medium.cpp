/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "stdio.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head){
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *n1 = head;
        ListNode *n2 = head->next;
        ListNode *n0 = dummy;
        ListNode *temp= NULL;

        bool flag = 0;
        while (n2) {
            if (n1->val == n2->val) {
                flag = 1;
                temp=n1;
                delete temp;
                n2 = n2->next;
                n1->next = n2;
            } else if (n1->val != n2->val && flag) {
                flag = 0;
                temp=n1;
                delete temp;
                n1 = n2;
                n2 = n2->next;
                n0->next = n1;
            } else {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
        }
        if(flag){
            n0->next=n2;
        }
        return dummy->next;
    }
};

void pList(ListNode *h) {
    while (h) {
        printf("%d\t", h->val);
        h = h->next;
    }
}

int main() {
//    ListNode n1(1), n2(1), n3(1), n4(2), n5(3);
//    ListNode n1(1), n2(2), n3(3), n4(3), n5(4), n6(4), n7(5);
//    ListNode *n1=new ListNode(1);
//    ListNode *n2=new ListNode(1);
    ListNode *n1=new ListNode(1);
    ListNode *n2=new ListNode(2);
    ListNode *n3=new ListNode(3);
    ListNode *n4=new ListNode(3);
    ListNode *n5=new ListNode(4);
    ListNode *n6=new ListNode(4);
    ListNode *n7=new ListNode(5);


    Solution solve;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next=NULL;

    ListNode *h1 = solve.deleteDuplicates(n1);
    pList(h1);
    return 0;
}
