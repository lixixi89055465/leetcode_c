//
// Created by nanji on 3/23/21.
//
/**
 * 341. 扁平化嵌套列表迭代器
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。



示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include "vector"
#include "stack"

class NestedInteger {
private:
    std::vector<NestedInteger> list;
    int value = 0;
public:
    NestedInteger(std::vector<NestedInteger> list, int value) {
        this->list = list;
        this->value = value;
    }

    bool isInteger() {
        return getList().size() == 0;
    }

    int getInteger() {
        return value;
    }

    std::vector<NestedInteger> getList() {
        return list;
    }
};

typedef struct NestNode {
    std::vector<NestedInteger> _nestedList;
    int index;
} Node;

class NestedIterator {
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        this->_nestedList = nestedList;
        int index = 0;
        Node node = {_nestedList, index};
        _stack.push_back(node);
    }

    int next() {
        if (hasNext()) {
            this->flag = false;
            return this->value;
        }
        return -1;
    }


    bool hasNext() {
        if (flag) {
            return true;
        }
        return dfs();
    }

    bool dfs() {
        while (!_stack.empty()) {
            Node node = _stack.back();
            if (node._nestedList.size() <= node.index) {
                _stack.pop_back();
                _stack.back().index++;
                continue;
            }
            if (node._nestedList[node.index].isInteger()) {
                this->flag = true;
                this->value = node._nestedList[node.index].getInteger();
                _stack.back().index++;
                return true;
            } else {
                Node node1 = {node._nestedList[node.index].getList(), 0};
                _stack.push_back(node1);
            }
        }
        return false;
    }

private:
    std::vector<NestedInteger> _nestedList;
    std::vector<Node> _stack;
    bool flag = false;
    int value = -1;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
    std::vector<NestedInteger> list;

    NestedInteger in1 = NestedInteger(list, 1);
    NestedInteger in2 = NestedInteger(list, 1);
    std::vector<NestedInteger> list1;
    list1.push_back(in1);
    list1.push_back(in2);

    NestedInteger in3 = NestedInteger(list, 1);
    NestedInteger in4 = NestedInteger(list, 1);
    std::vector<NestedInteger> list2;
    list2.push_back(in3);
    list2.push_back(in4);

    NestedInteger in5 = NestedInteger(list1, 2);

    NestedInteger in6 = NestedInteger(list, 2);
    NestedInteger in7 = NestedInteger(list2, 17);
    std::vector<NestedInteger> in8;


    in8.push_back(in5);
    in8.push_back(in6);
    in8.push_back(in7);

    NestedIterator solve = NestedIterator(in8);
    printf("222000::%d\n", solve.next());
    printf("333000::%d\n", solve.next());
    printf("444000::%d\n", solve.next());
    printf("444000::%d\n", solve.next());
    printf("444000::%d\n", solve.next());
    return 0;
}





