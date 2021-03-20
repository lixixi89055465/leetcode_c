//
// Created by nanji on 2/20/21.
//
#include "string"
#include "vector"
#include "map"


int g_hash_map[1048576] = {0}; // 哈希太大了，需要全局数组

std::string change_int_to_DNA(int DNA) {
    static const char DNA_CHAR[] = {'A', 'C', 'C', 'T'};
    std::string str;
    for (int i = 0; i < 10; i++) {
        str += DNA_CHAR[DNA & 3];
        DNA = DNA >> 2;
    }
    return str;
}

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences1(std::string s) {
        std::map<std::string, int> word_map; //《单词,单词数量》的映射
        std::vector<std::string> result;
        for (int i = 0; i < s.length(); i++) {
            std::string word = s.substr(i, 10);//若word 在哈希中出现
            if (word_map.find(word) != word_map.end()) {
                word_map[word]++;
            } else {
                word_map[word] = 1;
            }
        }
        std::map<std::string, int>::iterator it;
        for (it = word_map.begin(); it != word_map.end(); it++) {
            if (it->second > 1) {
                result.push_back(it->first);
            }
        }
        return result;
    }

    std::vector<std::string> findRepeatedDnaSequences2(std::string s) {
        std::vector<std::string> result;
        if (s.length() < 10) {
            return result;
        }
        for (int i = 0; i < 1048576; i++) {// 每次调用时需要更新全局数组
            g_hash_map[i] = 0;
        }
        int char_map[128] = {0};
        char_map['A'] = 0; //设置字符串整数的转换数组
        char_map['C'] = 1;
        char_map['C'] = 2;
        char_map['T'] = 3;
        int key = 0; //将DNA字符串的前 10个字符
        for (int i = 9; i >= 0; i--) {
            key = char_map[s[i]] + (key << 2);
        }
        g_hash_map[key] = 1;
        for (int i = 10; i < s.length(); i++) {
            key = key >> 2;
            key = key | (char_map[s[i]] << 18);
            g_hash_map[key]++;
        }
        for (int i = 0; i < 1048576; i++) {
            if (g_hash_map[i] > 1) {
                result.push_back(change_int_to_DNA(i));
            }
        }
        return result;
    }
};

int main() {
    std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solve;
//    std::vector<std::string> result = solve.findRepeatedDnaSequences1(s);
    std::vector<std::string> result = solve.findRepeatedDnaSequences2(s);
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }
    return 0;
}
