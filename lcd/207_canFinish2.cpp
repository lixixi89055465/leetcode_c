//
// Created by nanji on 1/11/21.
//

#include "vector"
#include "queue"
#include "stdio.h"

struct GraphNode {
    int label;
    std::vector<GraphNode *> neightbors;

    GraphNode(int x) : label(x) {}
};

const int MAX_N = 5;

class Solution {
public:


    bool canFinish(int numCourses,
                   std::vector<std::pair<int, int>> &prerequisites) {
        std::vector<GraphNode *> graph;
        std::vector<int> degree;//入度数组
        for (int i = 0; i < numCourses; i++) {
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neightbors.push_back(end);
//            degree[end->label]++;
            degree[prerequisites[i].first]++;
        }
        std::queue<GraphNode *> Q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                Q.push(graph[i]);
            }
        }
        while (!Q.empty()) {
            GraphNode *node = Q.front();
            Q.pop();
            for (int i = 0; i < node->neightbors.size(); i++) {
                degree[node->neightbors[i]->label]--;
                if (degree[node->neightbors[i]->label] == 0) {
                    Q.push(node->neightbors[i]);
                }
            }

        }
        for (int i = 0; i < graph.size(); i++) {
            delete graph[i];
        }
        for (int i = 0; i < graph.size(); i++) {
            if (degree[i]) {
                return false;
            }
        }
        return true;

    }

};


int main() {
    std::vector<std::pair<int, int>> prerequisites;
    prerequisites.push_back(std::make_pair(0, 0));
    prerequisites.push_back(std::make_pair(1, 0));
    prerequisites.push_back(std::make_pair(2, 1));
    prerequisites.push_back(std::make_pair(3, 2));
    Solution solution;
    printf("%d\n", solution.canFinish(4, prerequisites));
    return 0;
}
