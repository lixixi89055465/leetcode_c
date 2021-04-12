//
// Created by nanji on 4/12/21.
//
/**
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
示例 3：

输入：nums = [1]
输出："1"
示例 4：

输入：nums = [10]
输出："10"

 */

#include "vector"
#include "string"
#include "stack"

bool myfunction(std::string i, std::string j) {
    std::string tmpi = i + j;
    std::string tmpj = j + i;
    return tmpi.compare(tmpj) > 0;
}

std::string int2Str(int num) {
    if (num == 0) {
        return "0";
    }
    std::stack<int> s;
    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }
    std::string i = "";
    while (!s.empty()) {
        i += s.top() + '0';
        s.pop();
    }
    return i;
}

class Solution {
public:
    std::string largestNumber(std::vector<int> &nums) {
        int count = 0;
        std::vector<std::string> vecStr;
        for (int i = 0; i < nums.size(); i++) {
            vecStr.push_back(int2Str(nums[i]));
            if (nums[i] == 0) {
                count++;
            }
        }
        if (count == nums.size()) {
            return 0;
        }
        std::sort(vecStr.begin(), vecStr.end(), myfunction);
        std::string str = "";
        for (int i = 0; i < vecStr.size(); i++) {
            str += vecStr[i];
        }
        return str;
    }
};

int main() {
    std::vector<int> nums = {3, 30, 34, 5, 9};
//    std::vector<int> nums = {3, 30};
    Solution solve;
    std::string s = solve.largestNumber(nums);
    printf("result is %s\n", s.c_str());
    std::string i = "30";
    std::string j = "3";
    std::string tmpi = i + j;
    std::string tmpj = j + i;
    return 0;
}