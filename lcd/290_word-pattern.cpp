//
// Created by nanji on 2/19/21.
//

#include "string"
#include "map"

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::map<std::string, char> word_map;//单词到pattern字符的映射
        char used[128] = {0}; //已被映射的pattern 字符
        std::string word;  //临时保存拆分出的单词
        int pos = 0;// 当前指向的pattern 字符  ( 无需特殊处理最后一个单词了）
        str.push_back(' '); //str尾部push 一个空格，使得遇到空格拆分单词
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {// 遇到空格，即拆分出一个新单词
                if (pos == pattern.length()) {
                    return false;
                }// 若单词未出现在hash映射中
                if (word_map.find(word) == word_map.end()) {
                    if (used[pattern[pos]]) {
                        return false;
                    }
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;
                } else {
                    if (word_map[word] != pattern[pos]) {
                        return false;
                    }
                }
                word = ""; //完成一个单词的插入和查询后，清空 word
                pos++; //指向 pattern 字符的pos指针前移

            } else {
                word += str[i];
            }
        }

        if (pos != pattern.length()) {
            return false;
        }
        return true;
    }
};

int main() {
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    Solution solve;
    printf("%d\n", solve.wordPattern(pattern, str));
    return 0;
}