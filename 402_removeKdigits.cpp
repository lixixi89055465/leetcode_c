//
// Created by nanji on 2020/10/7.
//

#include <string>
#include "vector"
#include "queue"

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::vector<int> S;
        std::string result = "";
        for (int i = 0; i < num.length(); i++) {
            int number = num[i] - '0';
            while (S.size() != 0 && S[S.size() - 1] > number && k > 0) {
                S.pop_back();
                k--;
            }
            if (number != 0 || S.size() != 0) {
                S.push_back(number);//将数字number压入栈中
            }
        }
        while (S.size() != 0 && k > 0) {
            S.pop_back();
            k--;
        }   //将栈中元素 从头遍历，存储至result
        for (int i = 0; i < S.size(); i++) {
            result.append(1, '0' + S[i]);
        }
        if (result == "") {
            result = "0";//如果result为空 ，result即为0
        }
        return result;
    }
};
int main(){
    Solution solve;
    std::string result=solve.removeKdigits("1432219",3);
    printf("%s\n",result.c_str());
    std::string result2=solve.removeKdigits("100200",1);
    printf("%s\n",result2.c_str());
    return 0;
}
