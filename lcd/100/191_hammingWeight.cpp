//
// Created by nanji on 3/22/21.
//

#include <cstdint>
#include "stdio.h"

void printBite(uint32_t n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", n & (1 << i) ? 1 : 0);
    }
    printf("\n");
}

class Solution {
public:
    int hammingWeight3(uint32_t n) {
        printBite(n);
        printf("0x55555555:");
        printBite(0x55555555);
        n = n - ((n >> 1) & 0x55555555);
        printBite(n);
        printf("0x33333333:");
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        printBite(0x33333333);
        printBite(n);
        printf("0x0f0f0f0f:");
        n = (n + (n >> 4)) & 0x0f0f0f0f;
        printBite(0x0f0f0f0f);
        printBite(n);
        n = n + (n >> 8);
        printBite(n);
        n = n + (n >> 16);
        printBite(n);
        printBite(0x3f);
        return n & 0x3f;
    }

    int hammingWeight2(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (i << i)) {
                ret++;
            }
        }
        return ret;
    }

    int hammingWeight1(uint32_t n) {
        int count = 0;
        while (n) {
            if (n % 2) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

int main() {
    Solution solve;
    int result = solve.hammingWeight3(262143);
    printf(" result is %d\n", result);
    return 0;
}