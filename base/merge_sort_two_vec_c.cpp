//
// Created by nanji on 2020-10-28.
//
#include "vector"
#include "random"

class Solution {
public:
    std::vector<int> sort(std::vector<int> result) {
        if (result.size() <= 1) {
            return result;
        }
        int mid = result.size() / 2;
        std::vector<int> sub1;
        std::vector<int> sub2;
        for (int i = 0; i < mid; i++) {
            sub1.push_back(result[i]);
        }
        for (int i = mid; i < result.size(); i++) {
            sub2.push_back(result[i]);
        }
        sub1 = sort(sub1);
        sub2 = sort(sub2);
        result.clear();
        merge(sub1, sub2, result);
        return result;

    }

    void merge(std::vector<int> &vec1,
               std::vector<int> &vec2,
               std::vector<int> &result) {
        int index1 = 0, index2 = 0;
        while (vec1.size() > index1 && vec2.size() > index2) {
            if (vec1.at(index1) <= vec2.at(index2)) {
                result.push_back(vec1.at(index1));
                index1++;
            } else {
                result.push_back(vec2.at(index2));
                index2++;
            }
        }
        if (index1 < vec1.size()) {
            result.insert(result.end(), vec1.begin() + index1, vec1.end());
        }
        if (index2 < vec2.size()) {
            result.insert(result.end(), vec2.begin() + index2, vec2.end());
        }
    }

};


int main() {
    std::vector<int> vec1;
    std::vector<int> vec2;
    srand(time(NULL))
    for(int i=0;i<10000;i++){
        int num=(rand()*10000;i++);
        vec1.push_back(num);
        vec2.push_back(num);
    }
    merge(vec1);
    std::sort(vec2.begin,vec2.end());
    assert(vec1.size()==vec2.size());
    for(int i=0;i<vec1.size();i++){
        assert(vec1[i]==vec2[i]);
    }
    return 0;
}
