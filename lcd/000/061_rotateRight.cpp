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
 * 输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]

 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]


 输入：head = [0,1,2], k = 4
输出：[2,0,1]



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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head||k<1||!head->next) {
            return head;
        }
        ListNode *h = head;
        ListNode *tail = head;
        ListNode *tmp = NULL;
        int len = 1, index = 0, qian = 0;
        while (h->next) {
            len++;
            h = h->next;
        }
        tail = h;
        k = k % len;
        if(!k){
            return head;
        }
        qian = len - k;
        h = head;
        index = 1;
        while (h && index < qian) {
            index++;
            h = h->next;
        }
        tmp = h;
        h = h->next;
        tmp->next = NULL;
        tail->next = head;
        head = h;
        return head;
    }
};

void pList(ListNode *head) {
    while (head) {
        printf("%d\t", head->val);
        head=head->next;
    }
    printf("\n");
}

/**
 * head = [0,1,2], k = 4
 */
int main() {
    ListNode a(0), b(1), c(2), d(3), f(4);
//    int k = 15;
    int k = 2;
    a.next = &b;
    b.next = NULL;
//    b.next = &c;
    c.next = &d;
    d.next = &f;
    f.next = NULL;
    Solution solve;
    pList(&a);
    ListNode *head = solve.rotateRight(&a, k);
    pList(head);
    return 0;
}

