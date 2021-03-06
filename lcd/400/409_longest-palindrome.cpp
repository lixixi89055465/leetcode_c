//
// Created by nanji on 2/19/21.
//

#include"string"

class Solution {
public:
    int longestPalindrome(std::string s) {
        int char_map[128] = {0}; //字符hash
        int max_length = 0; //回文串偶数部分的最大长度
        int flag = 0;//是否有中心点
        for (int i = 0; i < s.length(); i++) {
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (char_map[i] % 2 == 0) {
                max_length += char_map[i];
            } else {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag;
    }
};

int main() {
    std::string s = "abccccddaa";
    Solution solve;
    printf("%d\n", solve.longestPalindrome(s));
    return 0;
}