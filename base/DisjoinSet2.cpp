//
// Created by nanji on 3/8/21.
//


#include "vector"

class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }

    int find(int p) {
        while (p != _id[p]) {
            _id[p] = _id[_id[p]];
            p = _id[p];

        }
        return p;
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
    std::vector<int> _size;
    int _count;
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
