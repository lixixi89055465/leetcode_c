//
// Created by nanji on 2020-10-06.
//


#include<stdio.h>
#include<queue>
#include<vector>

class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {//最小堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
        for (int i = 0; i < nums.size(); i++) { //遍历nums 数组
            if (Q.size() < k || Q.top() > nums[i]) {
                Q.push(nums[i]);
            } else if (Q.top() < nums[i]) {
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top(); //返回堆顶
    }
};
int main(){
    std::vector<int>nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    Solution solve;
    printf("%d \n",solve.findKthLargest(nums,2));
    printf("test");
    return 0;
}

