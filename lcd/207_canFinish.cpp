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

    bool DFS_graph(GraphNode *node, int visit[]) {
        std::queue<GraphNode *> Q;
        Q.push(node);
        visit[node->label] = 1;
        while (!Q.empty()) {
            GraphNode *node = Q.front();
            Q.pop();
            printf("%d\t", node->label);
            for (int i = 0; i < node->neightbors.size(); i++) {
                if (visit[i] == 0) {
                    Q.push(node->neightbors[i]);
                    visit[node->neightbors[i]->label] = 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool canFinish(int numCourses,
                   std::vector<std::pair<int, int>> &prerequisites) {
        int visit[MAX_N] = {0};
        std::queue<std::pair<int, int>> Q;
        std::vector<GraphNode *> graph; //邻接表
        for (int i = 0; i < numCourses; i++) {
            graph.push_back(new GraphNode(i));
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
                return false;
            }
        }
        for (int i = 0; i < numCourses; i++) {
            delete graph[i];
        }
        return true;
    }
};

int main() {

}