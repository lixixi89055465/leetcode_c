//
// Created by nanji on 1/11/21.
//

#include "stdio.h"
#include "vector"

struct GraphNode {
    int label;
    std::vector<GraphNode *> neightbors;

    GraphNode(int x) : label(x) {};
};

void DFS_graph(GraphNode *node, int visit[]) {
    visit[node->label] = 1;
    printf("%d\t", node->label);
    for (int i = 0; i < node->neightbors.size(); i++) {
        if (visit[node->neightbors[i]->label] == 0) {
            DFS_graph(node->neightbors[i], visit);
        }
    }
}

int main() {
    const int MAX_N = 5;
    GraphNode *Graph[MAX_N];//5个顶点
    for (int i = 0; i < MAX_N; i++) {
        Graph[i] = new GraphNode(i);
    }
    Graph[0]->neightbors.push_back(Graph[2]);
    Graph[0]->neightbors.push_back(Graph[4]);
    Graph[1]->neightbors.push_back(Graph[0]);
    Graph[1]->neightbors.push_back(Graph[2]);
    Graph[2]->neightbors.push_back(Graph[3]);
    Graph[3]->neightbors.push_back(Graph[4]);
    Graph[4]->neightbors.push_back(Graph[3]);
    int visit[MAX_N] = {0};

    for (int i = 0; i < MAX_N; i++) {
        if (visit[i]==0) {
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
