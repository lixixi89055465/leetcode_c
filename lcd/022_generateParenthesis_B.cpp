//
// Created by nanji on 2020-10-25.
//

#include "stdio.h"
#include "vector"
#include "string"

class Solution {
public:
    void generateParenthesis(std::string item, int n, int left, int right, std::vector<std::string> &result) {
        if (item.size() == 2 * n) {
            result.push_back(item);
            return;
        }
        if (left >= right) {
            if (left < n) {
                generateParenthesis(item + '(', n, left + 1, right, result);
            }
            if (right < n) {
                generateParenthesis(item + ')', n, left, right + 1, result);
            }
        }

    }
};

int main() {
    printf("tinan");
    std::vector<std::string> result;
    Solution solve;
    std::string str = "";
    solve.generateParenthesis(str, 3, 0, 0, result);
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }

}