//
// Created by nanji on 2020-10-25.
//

#include "stdio.h"
#include "vector"
#include "string"

class Solution {
public:
    void generateParenthesis(std::string item, int n, std::vector<std::string> &result) {
        if (item.size() == 2 * n) {
            result.push_back(item);
            return;
        }

        generateParenthesis(item + '(', n, result);
        generateParenthesis(item + ')', n, result);

    }
};

int main() {
    printf("tinan\n");
    std::vector<std::string> result;
    Solution solve;
    std::string str="";
    solve.generateParenthesis(str, 2, result);
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }

}