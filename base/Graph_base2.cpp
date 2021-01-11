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
    printf("Graph:\n");
    for (int i = 0; i < MAX_N; i++) {
        printf("Label (%d):", i);
        for (int j = 0; j < Graph[i]->neightbors.size(); j++) {
            printf("%d\t", Graph[i]->neightbors[j]->label);
        }
        printf("\n");
    }
    for (int i = 0; i < MAX_N; i++) {
        delete Graph[i];
    }
    return 0;
}
