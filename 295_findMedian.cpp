//
// Created by nanji on 2020-10-06.
//
#include "stdio.h"
#include "queue"

class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> big_queue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;

public:
    MedianFinder() {

    }//向数据结构添加一个整数
    void addNum(int num) {
        if (big_queue.empty()) {
            big_queue.push(num);
            return;
        }
        if (big_queue.size() == small_queue.size()) {
            if (num < big_queue.top()) {
                big_queue.push(num);
            } else {
                small_queue.push(num);
            }
        }else if(big_queue.size()<small_queue.size()){
            if(num>big_queue.top()){
                small_queue.push(num);
            }else {
                big_queue.pop();
                big_queue.push(num);
            }
        }

    }//返回该数据结构中维护的数据的中位数
    double findMedian() {

    }
};

int main() {
    MedianFinder M;
    M.addNum(2);
    M.addNum(1);
    printf("%lf\n", M.findMedian());
    M.addNum(4);
    printf("%lf\n", M.findMedian());
    M.addNum(3);
    printf("%lf\n", M.findMedian());
    return 0;

}
