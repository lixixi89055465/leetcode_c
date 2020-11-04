//
// Created by nanji on 2020-10-28.
//
//tst
#include "vector"

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int> &nums) {
        std::vector<std::pair<int, int>> vec;
        std::vector<int> count;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(std::make_pair(nums[i], i));
            count.push_back(0); //将nums[i] 与 i绑定为pair<nums[i],i>
        }
        merge_sort(vec, count);
        return count;
    }

private:
    void merge_sort_two_vec(
            std::vector<std::pair<int, int>> &sub_vec1,
            std::vector<std::pair<int, int>> &sub_vec2,
            std::vector<std::pair<int, int>> &vec,
            std::vector<int> &count) {
        for (int i = 0; i < sub_vec1.size(); i++) {
            for (int j = 0; j < sub_vec2.size(); j++) {
                if (sub_vec1[i].first > sub_vec2[j].first) {
                    count[sub_vec1[i].second]++;
                }
            }
        }
    }

    void merge_sort(std::vector<std::pair<int, int>> &vec,
                    std::vector<int> &count) {
        if (vec.size() < 2) {
            return; //字问题足够小的时候，直接求解
        }
        int mid = vec.size() / 2;
        std::vector<std::pair<int, int>> sub_vec1;
        std::vector<std::pair<int, int>> sub_vec2;
        for (int i = 0; i < mid; i++) {
            sub_vec1.push_back(vec[i]);
        }
        for (int i = mid; i < vec.size(); i++) {
            sub_vec2.push_back(vec[i]);
        }
        merge_sort(sub_vec1, count);
        merge_sort(sub_vec2, count);
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(-7);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);
    Solution solve;
    std::vector<int> count = solve.countSmaller(nums);
    printf("\n");
    for (int i = 0; i < count.size(); i++) {
        printf("%d\t", count[i]);
    }
    return 0;
}