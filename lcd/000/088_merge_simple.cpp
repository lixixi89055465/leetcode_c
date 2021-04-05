//
// Created by nanji on 4/5/21.
//

#include "vector"

class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        int p1 = m - 1, p2 = n - 1, tail = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[tail] = nums1[p1];
                p1--;
            } else {
                nums1[tail] = nums2[p2];
                p2--;
            }
            tail--;
        }
        while (p2 >= 0) {
            nums1[p2] = nums2[p2];
            p2--;
        }
    }
};

int main() {
//    std::vector<int> num1 = {1, 2, 4};
    std::vector<int> num1 = {0};
    std::vector<int> num2 = {2, 3, 4};
    Solution solve;
    solve.merge(num1,0, num2,3);
    for(int i=0;i<6;i++){
        printf("%d\r",num1[i]);
    }
    return 0;
}