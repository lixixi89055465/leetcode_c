//
// Created by nanji on 2/25/21.
//

#include "vector"

class Solution {
public:
    bool makesquare(std::vector<int> &nums) {
        if (nums.size() < 4) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; //累加求和
        }
        if (sum % 4 != 0) {
            return false;
        }
        std::sort(nums.rbegin(), nums.rend());
        int bucket[4] = {0};
        return generate(0, nums, sum / 4, bucket);
    }

private:
    bool generate(int i, std::vector<int> &nums, int target, int bucket[]) {
        if (i >= nums.size()) {
            return bucket[0] == target && bucket[1] == target
                   && bucket[2] == target && bucket[3] == target;
        }
        for (int j = 0; j < 4; j++) {
            if (bucket[j] + nums[j] > target) {
                continue;
            }
            bucket[j] += nums[i];
            if (generate(i + 1, nums, target, bucket)) {
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};