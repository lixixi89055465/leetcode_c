//
// Created by nanji on 2020-10-16.
//

#include "stdio.h"
#include "vector"

typedef struct Node {
    int start;
    int end;
    bool status; //当status 为 1是表示已经被排除。反之亦然
} Node;

class Solution {
public:

    int findMinArrowShots(std::vector<Node> &nums) {
        int count = 0;
        int start = nums[0].start;
        int end = nums[0].end;
        for (std::vector<Node>::iterator it = nums.begin(); it != nums.end(); it++) {
            it->status = true;
            if (it->start > end) {
                end = it->end;
                count++;
            }
        }
        return count;
    }
};

int sortByBegin(const Node &v1, const Node &v2) {
    return v1.start < v2.start;
}

void MyPushBack(std::vector<Node> &nums, int start, int end) {
    if (start < end) {
        Node ele = {start, end, false};
        nums.push_back(ele);
    }
}

void printVector(std::vector<Node> &nums) {
    for (std::vector<Node>::iterator it = nums.begin(); it != nums.end(); it++) {
        printf("start:%d  ;  end: %d   ; status:  %d  \n", it->start, it->end, it->status);
    }
}

int main() {
    std::vector<Node> vectors;
    MyPushBack(vectors, 4, 9);
    MyPushBack(vectors, 9, 10);
    MyPushBack(vectors, 9, 12);
    MyPushBack(vectors, 6, 8);
    MyPushBack(vectors, 7, 9);
    MyPushBack(vectors, 2, 5);
    MyPushBack(vectors, 3, 8);
    MyPushBack(vectors, 4, 5);
    MyPushBack(vectors, 12, 15);
    MyPushBack(vectors, 19, 25);
    MyPushBack(vectors, 22, 28);
    MyPushBack(vectors, 22, 28);
    MyPushBack(vectors, 22, 28);
    MyPushBack(vectors, 22, 28);
    MyPushBack(vectors, 32, 88);
    printVector(vectors);

    printf("111111111\n");
    std::sort(vectors.begin(), vectors.end(), sortByBegin);
    printVector(vectors);
    Solution solution;
    int count=solution.findMinArrowShots(vectors);
    printf("count: %d \n",count);

}

