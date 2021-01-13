//
// Created by nanji on 1/13/21.
//

#include "stdio.h"
#include "vector"

bool binary_search(std::vector<int> &sort_array, int target) {
    int begin = 0;
    int end = sort_array.size() - 1;
    int mid = 0;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (target == sort_array[mid]) {
            return true;
        } else if (target < sort_array[mid]) {
            end = mid - 1;
        } else if (target > sort_array[mid]) {
            begin = mid + 1;
        }
    }
    return false;
}
