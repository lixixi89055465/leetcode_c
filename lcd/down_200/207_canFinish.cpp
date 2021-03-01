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
                if (visit[node->neightbors[i]->label] == 0) {
                    Q.push(node->neightbors[i]);
                    visit[node->neightbors[i]->label] = 1;
                }
            }
        }

    }

    void canFinish(GraphNode *node) {
        int visit[MAX_N] = {0};


    }
};


int main() {
    const int MAX_N = 5;
    GraphNode *Graph[MAX_N];//5个顶点
    for (int i = 0; i < MAX_N; i++) {
        Graph[i] = new GraphNode(i);
    }
    Graph[0]->neightbors.push_back(Graph[4]);
    Graph[0]->neightbors.push_back(Graph[2]);
    Graph[1]->neightbors.push_back(Graph[0]);
    Graph[1]->neightbors.push_back(Graph[2]);
    Graph[2]->neightbors.push_back(Graph[3]);
    Graph[3]->neightbors.push_back(Graph[4]);
    Graph[4]->neightbors.push_back(Graph[3]);
    int visit[MAX_N] = {0};

    for (int i = 0; i < MAX_N; i++) {
        if (visit[i] == 0) {
            printf("From label ( %d ) ", Graph[i]->label);
            DFS_graph(Graph[i], visit);
            printf("\n");
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        delete Graph[i];
    }
    return 0;
}
