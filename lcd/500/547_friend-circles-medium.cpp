//
// Created by nanji on 3/7/21.
//
#include "vector"

void DFS_graph(int u,
               std::vector<std::vector<int>> &graph,
               std::vector<int> &visit) {
    visit[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        if (graph[u][i] == 1 && visit[i] == 0) {
            DFS_graph(i, graph, visit);
        }
    }

}

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>> &M) {
        std::vector<int> visit(M.size(), 0);
        int count = 0;
        for (int i = 0; i < M.size(); i++) {
            if (0 == visit[i]) {
                DFS_graph(i, M, visit);
                count++;
            }
        }
        return count;
    }
};

int main() {
    return 0;
}