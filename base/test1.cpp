//
// Created by nanji on 3/22/21.
//
#include "stdio.h"

void printBite(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", n & (1 << i) ? 1 : 0);
    }
    printf("\n");
}

class Solution {
public:
    int hammingWeight3(int n) {
        printf("n:%d:", n);
        printBite(n);
        printf("n>>1:");
        printBite(n >> 1);
        printf("0x55555555:\t\t");
        printBite(0x55555555);
        printf("(n >> 1) & 0x55555555:\t");
        printBite((n >> 1) & 0x55555555);
//        n = n - ((n >> 1) & 0x55555555);
        printf("n - ((n >> 1) & 0x55555555):");
        printBite((n - ((n >> 1) & 0x55555555)));
        printf("%d", n);
    }

};

int main() {
    Solution solve;
    int result = solve.hammingWeight3(362143);
    printf(" result is %d\n", result);
    return 0;
}