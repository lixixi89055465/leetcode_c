#include<stdio.h>
#include<queue>
#include<vector>



int main() {
    std::priority_queue<int>
            big_heap;//默认构造是最大堆
    std::priority_queue<int, std::vector<int>,//最小堆构造方法
            std::greater<int>>
            small_heap;
    std::priority_queue<int, std::vector<int>, std::less<int>>
            big_heap2; //最大堆构造方法

    if (big_heap.empty()) {
        printf("big_heap is empty !!\n");
    }

    int test[] = {6, 10, 1, 7, 99, 4, 33};
    for (int i = 0; i < 7; i++) {
        big_heap.push(test[i]);
    }
    printf("big heap.top= %d\n ", big_heap.top());

    big_heap.push(1000);

    printf("big heap.top= %d \n", big_heap.top());

    for (int i = 0; i < 3; i++) {
        big_heap.pop();
    }
    printf("big_heap.top = %d \n", big_heap.top());
    printf("big_heap.size = %d \n", big_heap.size());
    return 0;
}