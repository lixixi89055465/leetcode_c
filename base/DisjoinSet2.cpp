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
        int i = find(p);
        int j = find(q);
        if (i == j) {
            return;
        }
        if (_size[i] < _size[j]) {
            _id[i] = j;
            _size[j] += _size[i];
        } else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
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

    int count() {
        return _count;
    }

private:
    std::vector<int> _id;
    std::vector<int> _size;
    int _count;
};

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>> &M) {
        DisjointSet disjointSet_set(M.size());
        for (int i = 0; i < M.size(); i++) {
            for (int j = i + 1; j < M.size(); j++) {
                if (M[i][j]) {
                    disjointSet_set.union_(i, j);
                }
            }
        }
        return disjointSet_set.count();
    }
};

int main() {
    /* DisjointSet disjointSet(8);
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
            disjointSet.find(2), disjointSet.find(5));*/

    int test[][3] = {{1, 1, 0},
                     {1, 1, 1},
                     {0, 1, 1}};
    std::vector<std::vector<int>> M(3, std::vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            M[i][j] = test[i][j];
        }
    }
    Solution solve;
    printf("%d\n", solve.findCircleNum(M));
    return 0;
}
