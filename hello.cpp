#include<stdio.h>

int main() {
    int key = 1024 * 1024 + 123456;
    printf("%d\n", key);
    key = key >> 2;
    printf("%d\n", key);
    key = key | (key >> 18);
    printf("%d\n", key);
    return 0;
}