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

    //节点访问状态，-1没有访问过，0代表正在访问，1代表已完成访问
    bool DFS_graph(GraphNode *node, int visit[]) {
        visit[node->label] = 0;
        for (int i = 0; i < node->neightbors.size(); i++) {
            if (visit[node->neightbors[i]->label] == -1) {
                if (DFS_graph(node->neightbors[i], visit) == 0) {
                    return false;
                }
            } else if (visit[node->neightbors[i]->label] == 0) {
                return false;
            }
        }
        visit[node->label] = 1;
        return true;
    }

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
            degree[end->label]++;
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
