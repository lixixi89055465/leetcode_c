//
// Created by nanji on 2/22/21.
//
#include <sys/socket.h>
#include "string"
#include "vector"
#include "map"
#include "queue"
#include "set"

class Solution {
public:
    bool connect(const std::string &word1, const std::string &word2) {
        int cnt = 0;//记录 word1 与 word2 不相等字符的个数
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    void construct_graph(std::string &beginWord,
                         std::vector<std::string> &wordList,
                         std::map<std::string, std::vector<std::string>> &graph) {
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            graph[wordList[i]] = std::vector<std::string>();
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (connect(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }


    }

    int BFS_graph(std::string &beginWord, std::string &endWord,
                  std::map<std::string, std::vector<std::string>> &graph) {
        std::queue<std::pair<std::string, int>> Q;// 搜索队列<顶点，步数>
        std::set<std::string> visit;// 记录已访问的顶点。
        Q.push(std::make_pair(beginWord, 1)); //添加起始点，起始步数为1
        visit.insert(beginWord); //标记起点已访问
        while (!Q.empty()) {
            std::string node = Q.front().first; //取队列头部节点与步数
            int step = Q.front().second;
            Q.pop();
            if (node == endWord) {
                return step;
            }
            const std::vector<std::string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++) {
                if (visit.find(neighbors[i]) == visit.end()) {
                    Q.push(std::make_pair(neighbors[i], step + 1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        return 0;

    }

    int ladderLength(std::string beginWord, std::string endWord,
                     std::vector<std::string> &wordList) {
        std::map<std::string, std::vector<std::string>> graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }
};

int main() {
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    Solution solve;
    int result = solve.ladderLength(beginWord, endWord, wordList);
    printf("result = %d \n", result);
    return 0;
}
