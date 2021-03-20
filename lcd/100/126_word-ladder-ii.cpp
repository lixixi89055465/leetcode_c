//
// Created by nanji on 2/22/21.
//
#include <sys/socket.h>
#include "string"
#include "vector"
#include "map"
#include "queue"
#include "set"

struct Qitem {
    std::string node;// 搜索节点
    int parent_pos;
    int step;// 到达当前节点的步数
    Qitem(std::string _node, int _parent_pos, int _step)
            : node(_node), parent_pos(_parent_pos), step(_step) {
    }
};

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

    int ladderLength(std::string beginWord, std::string endWord,
                     std::vector<std::string> &wordList) {
        std::map<std::string, std::vector<std::string>> graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph1(beginWord, endWord, graph);
    }

    void BFS_graph(std::string &beginWord, std::string &endWord,
                   std::map<std::string, std::vector<std::string>> &graph,
                   std::vector<Qitem> &Q,// 使用 vector 实现的队列，可保存所有信息
                   std::vector<int> &end_word_pos) {
        std::map<std::string, int> visit; //<单词，步数>
        int min_step = 0; //到达 endWord 的最小步数
        Q.push_back(Qitem(beginWord.c_str(), -1, 1));//起始单词的前驱为 -1
        visit[beginWord] = 1;// 标记起始单词步数为1
        int front = 1;
        while (front != Q.size()) {
            const std::string &node = Q[front].node;
            int step = Q[front].step;//取队列元素
            if (min_step != 0 && step > min_step) {
                break;
            }
            if (node == endWord) {
                min_step = step;
                end_word_pos.push_back(front);
            }
            const std::vector<std::string> &neightbors = graph[node];
            for (int i = 0; i < neightbors.size(); i++) {
                if (visit.find(neightbors[i]) == visit.end() ||
                    visit[neightbors[i]] == step + 1) {

                    Q.push_back(Qitem(neightbors[i], front, step + 1));
                    visit[neightbors[i]] = step + 1;//标记到达临接点neightbors[i]的最小步数
                }
            }

        }
        front++;
    }

    std::vector<std::vector<std::string>> findLadders(
            std::string beginWord, std::string endWord,
            std::vector<std::string> &wordList) {
        std::map<std::stsring, std::vector<std::string>> graph;
        construct_graph(beginWord, wordList, graph);
        std::vector<Qitem> Q;//使用vector 实现的队列
        std::vector<int> end_word_pos; //endWord 在搜索队列的位置
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);
        std::vector<std::vector<std::string>> result; //最终结果
        for (int i = 0; i < end_word_pos.size(); i++) {
            int pos = end_word_pos[i];
            std::vector<std::string> path;
            while (pos != -1) {
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(std::vector<std::string>());
            for (int j = path.size() - 1; j >= 0; j--) {
                result[i].push_back(path[j]);
            }
        }
        return result;
    }

};

void construct_graph(std::string &beginWord,
                     std::vector<std::string> &wordList,
                     std::map<std::string, std::vector<std::string>> &graph) {
    int has_begin_word = 0;
    for (int i = 0; i < wordList.size(); i++) {
        if (wordList[i] == beginWord) {
            has_begin_word = 1;
        }
        graph[wordList[i]] = std::vector<std::string>();
    }
    for (int i = 0; i < wordList.size(); i++) {
        for (int j = i + 1; j < wordList.size(); j++) {
            if (connect(wordList[i], wordList[j])) {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
        if (has_begin_word == 0 && connect(beginWord, wordList[i])) {
            graph[beginWord].push_back(wordList[i]);
        }

    }
}

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
    std::vector<std::vector<std::string>> result =
            solve.findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%s] ", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;


    return 0;
}
