//
// Created by nanji on 2/19/21.
//

#include "string"
#include "vector"

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int begin = 0;// 窗口的头指针
        int result = 0;
        std::string word = "";
        int char_map[128] = {0};
        for (int i = 0; i < s.length(); i++) {
            char_map[s[i]]++;
            if (char_map[s[i]] == 1) {
                word += s[i];
                if (result < word.length()) {
                    result = word.length();
                }
            } else { //将重复的字符 s[i]删除
                while (begin < i && char_map[s[i]] > 1) {
                    char_map[s[begin]]--;
                    begin++;
                }
                word = ""; //重新更新 word
                for (int j = begin; j <= i; j++) {
                    word += s[i];
                }
            }

        }
        return result;

    }
};

//abcdbghr
int main() {
    std::string s = "abcbadab";
    Solution solve;
    printf("%d\n", solve.lengthOfLongestSubstring(s));
    return 0;
}