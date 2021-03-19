//
// Created by nanji on 3/18/21.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "stdio.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {

        if (left == right) {
            return head;
        }
        int index = 1;
        ListNode *lNode = head;
        ListNode *ll = NULL, *lr = NULL, *ml = NULL, *mr = NULL, *rl = NULL, *rr = NULL;
        ll = head;
        if (left == 1) {
            ll = NULL;
            lr = NULL;
        }
        while (index < left) {
            lr = lNode;
            lNode = lNode->next;
            index++;
        }
        ml = lNode;
        ListNode *tmp1 = NULL, *tmp2 = NULL;
        while (index <= right) {
            tmp2 = lNode;
            lNode = lNode->next;
            tmp2->next = tmp1;
            tmp1 = tmp2;
            index++;
        }
        mr = tmp1;
        rl=lNode;
//        mr->next=tmp2;
        ml->next=rl;
        if(lr){
            lr->next=mr;
        }
        if(NULL==ll){
            return mr;
        }
        return head;
    }
};

void printList(ListNode *list) {
    while (list) {
        printf("%d\t", list->val);
        list = list->next;
    }
}

int main() {
//    head = [1,2,3,4,5], left = 2, right = 4
//    输出：[1,4,3,2,5]
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
//    e.next = NULL;
//    a.next = NULL;
//    b.next = NULL;
//    c.next = NULL;
    printList(&a);
    Solution solve;
//    ListNode*head=solve.reverseBetween(&a, 2, 4);
    ListNode *head=solve.reverseBetween(&a, 1, 2);
    printf("\n");
    printList(head);
    return 0;
}