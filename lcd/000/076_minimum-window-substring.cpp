//
// Created by nanji on 2/21/21.
//

#include "string"
#include "vector"

class Solution {
private:
    bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t) {
        for (int i = 0; i < vec_t.size(); i++) { //利用vec_t遍历t中出现的字符
            if (map_s[vec_t[i]] < map_t[vec_t[i]]) {
                return false;  //如果 s出现该字符的数量小玉t中出现该字符的数量。
            }
        }
        return true;
    }

public:
    std::string minWindow(std::string s, std::string t) {
        const int MAX_ARRAY_LEN = 128; //char 0-127，利用数组下标记录字符个数
        int map_t[MAX_ARRAY_LEN] = {0}; //记录t字符串各字符个数
        int map_s[MAX_ARRAY_LEN] = {0}; //记录s字符串各字符个数
        std::vector<int> vec_t; //记录t字符串中有哪些字符
        for (int i = 0; i < s.length(); i++) {
            map_s[s[i]]++; //遍历s,记录s字符串个字符个数
        }
        for (int i = 0; i < t.length(); i++) {
            map_t[t[i]]++; //遍历t,记录s字符串个字符个数
        }

        for (int i = 0; i < MAX_ARRAY_LEN; i++) {
            if (map_t[i] > 0) {
                vec_t.push_back(i);
            } //遍历，将字符串t中出现的字符串存储到vec_t 中
        }


        int windows_begin = 0;//最小窗口起始指针
        std::string result; //最小窗口对应的字符串
        for (int i = 0; i < s.length(); i++) {
            map_s[s[i]]++;
            while (windows_begin < i) { //窗口的头指针不能超过尾指针
                char begin_ch = s[windows_begin];
                if (map_t[begin_ch] == 0) { //如果当前头指针指向的字符没有在字符串t 出现
                    windows_begin++;
                }//头指针指向的字符出现在T中,窗口内有超过T中该字符个数的字符
                else if (map_s[begin_ch] > map_t[begin_ch]) {
                    map_s[begin_ch]--;
                    begin_ch++;// 窗口头指针前移
                } else {
                    break;
                }
            }
            if (is_window_ok(map_s, map_t, vec_t)) {
                int new_window_len = i - windows_begin + 1;
                if (result == "" || result.length() > new_window_len) {
                    result = s.substr(windows_begin, new_window_len);
                }//替换窗口所对应的字符串 //结果字符串为空，或者当前窗口字符串更小的时候更新结果

            }
        }
        return result;
    }
};

int main() {
    Solution solve;
    std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
    printf("%s\n", result.c_str());
    result = solve.minWindow("MADOBCCABEC", "ABCC");
    printf("%s\n", result.c_str());
    result = solve.minWindow("aa", "aa");
    printf("%s\n", result.c_str());


}
