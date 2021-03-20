//
// Created by nanji on 3/20/21.
//
/**
 * 根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：
该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include "vector"
#include "string"
#include "stack"


int string2int(std::string str) {
    int hao = 1;
    int value = 0;
    int i = 0;
    if (str[0] == '-') {
        hao = -1;
        i = 1;
    }
    for (; i < str.size(); i++) {
        value = value * 10 + str[i] - '0';
    }
    value *= hao;
    return value;
}

class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::stack<int> stack;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < tokens.size(); i++) {
//            if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/') {
//                stack.push(tokens[i][0]);
//            }
            switch (tokens[i][0]) {
                case '+':
                    s1 = stack.top();
                    stack.pop();
                    s2 = stack.top();
                    stack.pop();
                    stack.push(s2 + s1);
                    break;
                case '-':
                    if (tokens[i].size() == 1) {
                        s1 = stack.top();
                        stack.pop();
                        s2 = stack.top();
                        stack.pop();
                        stack.push(s2 - s1);
                        break;
                    } else {
                        stack.push(string2int(tokens[i]));
                    }
                    break;
                case '*':
                    s1 = stack.top();
                    stack.pop();
                    s2 = stack.top();
                    stack.pop();
                    stack.push(s2 * s1);
                    break;
                case '/':
                    s1 = stack.top();
                    stack.pop();
                    s2 = stack.top();
                    stack.pop();
                    stack.push(s2 / s1);
                    break;
                default:
                    stack.push(string2int(tokens[i]));
            }
        }
        return stack.top();
    }
};


//["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
int main() {
    Solution solve;
    std::vector<std::string> tokens;
    tokens.push_back("10");
    tokens.push_back("6");
    tokens.push_back("9");
    tokens.push_back("3");
    tokens.push_back("+");
    tokens.push_back("-11");
    tokens.push_back("*");
    tokens.push_back("/");
    tokens.push_back("*");
    tokens.push_back("17");
    tokens.push_back("+");
    tokens.push_back("5");
    tokens.push_back("+");
    int result = solve.evalRPN(tokens);
    printf("result is %d", result);
    return 0;
}
