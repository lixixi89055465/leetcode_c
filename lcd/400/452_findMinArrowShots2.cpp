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

int cmp(std::vector<int> &v1, std::vector<int> &v2) {
    return v1[0] < v2[0];
}

class Solution {
public:

    int findMinArrowShots(std::vector<std::vector<int>> &nums) {
        std::sort(nums.begin(), nums.end(), cmp);
        int count = 1;
        int begin = nums[0][0];
        int end = nums[0][1];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i][1] < end) {
                end = nums[i][1];
            }
            if (nums[i][0] < end) {
                continue;
            }
            count++;
            end=nums[i][1];

        }
        return count;
    }
};


int main() {
    std::vector<std::vector<int> > vectors;
    std::vector<int> a, b, c, d;
//    a.push_back(10);
//    a.push_back(16);
//    b.push_back(2);
//    b.push_back(8);
//    c.push_back(1);
//    c.push_back(6);
//    d.push_back(7);
//    d.push_back(12);


    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    c.push_back(5);
    c.push_back(6);
    d.push_back(7);
    d.push_back(8);
    vectors.push_back(a);
    vectors.push_back(b);
    vectors.push_back(c);
    vectors.push_back(d);

    printf("111111111\n");
    Solution solution;
    int count = solution.findMinArrowShots(vectors);
    printf("count: %d \n", count);

}

