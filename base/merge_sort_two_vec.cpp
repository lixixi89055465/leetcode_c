//
// Created by nanji on 2020-10-28.
//
#include "vector"
#include "random"

class Solution {
public:
    void merge(std::vector<int> &vec1,
               std::vector<int> &vec2,
               std::vector<int> &result) {
        int index1 = 0, index2 = 0;
        while (vec1.size()>index1 && vec2.size()>index2) {
            if (vec1.at(index1) <= vec2.at(index2)) {
                result.push_back(vec1.at(index1));
                index1++;
            } else {
                result.push_back(vec2.at(index2));
                index2++;
            }
        }
        if (index1 < vec1.size()) {
            result.insert(result.end(), vec1.begin()+index1, vec1.end());
        }
        if (!index2 < vec2.size()) {
            result.insert(result.end(), vec2.begin()+index2, vec2.end());
        }
    }

};

int main() {
    Solution solve;
    std::vector<int> vec1, vec2, result;
    for (int i = 0; i < 10; i++) {
        vec1.push_back(rand() % 100);
        vec2.push_back(rand() % 100);
    }
    std::sort(vec1.begin(),vec1.end());
    std::sort(vec2.begin(),vec2.end());

//    solve.merge()
    printf("\nvec1:\n");
    for (int i = 0; i < vec1.size(); i++) {
        printf("%d\t", vec1.at(i));
    }
    printf("\nvec2\n");
    for (int i = 0; i < vec2.size(); i++) {
        printf("%d\t", vec2.at(i));
    }
    solve.merge(vec1, vec2, result);
    printf("\nresult:\n");
    for (int i = 0; i < result.size(); i++) {
        printf("%d\t", result.at(i));
    }
    printf("\n");


    printf("%d", vec1.front());
    return 0;
}
