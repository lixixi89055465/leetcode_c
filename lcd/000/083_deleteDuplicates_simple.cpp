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

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head){
            return head;
        }
        ListNode *h = head;
        while (h->next) {
            if (h->val == h->next->val) {
                h->next = h->next->next;
            } else {
                h = h->next;
            }
        }
        return head;
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
