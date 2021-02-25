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

    int BFS_graph1(std::string &beginWord, std::string &endWord,
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
        return BFS_graph1(beginWord, endWord, graph);
    }

    void BFS_graph2(std::string &beginWord, std::string &endWord,
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
