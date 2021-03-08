//
// Created by nanji on 3/8/21.
//


#include "vector"

class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            _id.push_back(i);
        }
    }

    int find(int p) {
        return _id[p];
    }

    void union_(int p, int q) {
        int pid = find(p);
        int qid = find(q);
        if (pid == qid) {
            return;
        }
        for (int i = 0; i < _id.size(); i++) {
            if (_id[i] == pid) {
                _id[i] = qid;
            }
        }
    }

    void print_set() {
        printf("元素 : ");
        for (int i = 0; i < _id.size(); i++) {
            printf("%d\t", i);
        }
        printf("\n");
        printf("集合:\t");
        for (int i = 0; i < _id.size(); i++) {
            printf("%d\t", _id[i]);
        }
        printf("\n");
    }

private:
    std::vector<int> _id;
};

int main() {
    DisjointSet disjointSet(8);
    disjointSet.print_set();
    printf("Union(0,5) \n");
    disjointSet.union_(0, 5);
    disjointSet.print_set();
    printf("Find(0)= %d,find(5)=%d \n",
           disjointSet.find(0), disjointSet.find(5));
    printf("Find(2)= %d,find(5)=%d \n",
           disjointSet.find(2), disjointSet.find(5));
    disjointSet.union_(2, 4);
    disjointSet.print_set();
    disjointSet.union_(0, 4);
    disjointSet.print_set();
    printf("Find(2) = %d , Find(5) = %d \n",
           disjointSet.find(2), disjointSet.find(5));
    return 0;
}
