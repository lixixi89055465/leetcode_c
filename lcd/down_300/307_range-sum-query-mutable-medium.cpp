//
// Created by nanji on 3/9/21.
//


#include "vector"

class NumArray {
public:
    NumArray(std::vector<int> nums) {

    }

    void update(int i, int j) {

    }

    void sumRange(int i, int j) {

    }
};

void build_segment_tree(std::vector<int> &value,
                        std::vector<int> &nums,
                        int pos, int left, int right) {
    if (left == right) {
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value, nums, pos * 2 + 1, left, mid);
    build_segment_tree(value, nums, pos * 2 + 2, mid + 1, right);
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

void print_segment_tree(std::vector<int> &value,
                        int pos, int left, int right, int layer) {
    for (int i = 0; i < layer; i++) {
        printf("---");
    }
    printf("[%d %d][%d] : %d\n", left, right, pos, value[pos]);
    if (left == right) {
        return;
    }
    int mid = (left + right) / 2;
    print_segment_tree(value, pos * 2 + 1, left, mid, layer + 1);
    print_segment_tree(value, pos * 2 + 2, mid + 1, right, layer + 1);
}

int sum_range_segment_tree(std::vector<int> &value,
                           int pos, int left, int right,
                           int qleft, int qright) {
    if (qleft > right || qright < left) {
        return 0;
    }
    if (qleft <= left && qright >= right) {
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright)
           + sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
}