//
// Created by nanji on 2/19/21.
//
#include "vector"
#include "string"
#include "map"

void change_to_vector(std::string &str, std::vector<int> &vec) {
    for (int i = 0; i < 26; i++) {
        vec.push_back(0);
    }
    for (int i = 0; i < str.length(); i++) {
        vec[str[i] - 'a']++;
    }
}

class Solution {
public:

    std::vector<std::vector<std::string>> groupAnagrams2(
            std::vector<std::string> &strs) {
        std::map<std::vector<int>, std::vector<std::string>> anagram;
        std::vector<std::vector<std::string>> result;
        for (int i = 0; i < strs.size(); i++) {
            std::vector<int> vec;
            change_to_vector(strs[i], vec);
            if (anagram.find(vec) == anagram.end()) {
                std::vector<std::string> item;
                anagram[vec] = item;
            }
            anagram[vec].push_back(strs[i]);
        }
        std::map<std::vector<int>, std::vector<std::string>>::iterator it;
        for (it = anagram.begin(); it != anagram.end(); it++) {
            result.push_back((*it).second);
        }
        return result;
    }

    std::vector<std::vector<std::string>> groupAnagrams1(
            std::vector<std::string> &strs) {
        std::map<std::string, std::vector<std::string>> anagram;
        // 内部进行排序的各个单词为key,以字符串向量（vector<string>)为
        // value,存储各个字符数量相同的字符串(anagram)
        std::vector<std::vector<std::string>> result; //存储最终的结果
        for (int i = 0; i < strs.size(); i++) {
            std::string str = strs[i];
            std::sort(str.begin(), str.end()); //对str内部进行排序
            if (anagram.find(str) == anagram.end()) {//若无法在hash表中找到 str
                std::vector<std::string> item; // 设置一个空的字符串向量
                anagram[str] = item;
            }
            anagram[str].push_back(strs[i]);
        }
        std::map<std::string, std::vector<std::string>>::iterator it;
        for (it = anagram.begin(); it != anagram.end(); it++) {
            result.push_back((*it).second);
        }
        return result;//遍历hash表，将hash 表的value push进入最终结果
    }
};

int main() {
    std::vector<std::string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution solve;
    std::vector<std::vector<std::string>> result = solve.groupAnagrams2(strs);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%s]", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}