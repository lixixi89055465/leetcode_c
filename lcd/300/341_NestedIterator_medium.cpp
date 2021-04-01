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
public:
    bool isInteger() const;

    int getInteger() const;

    const std::vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            this->_stack.push(nestedList[i]);
        }
    }

    int next() {
        NestedInteger in;
        int i = 0;
        while (!this->_stack.top().isInteger()) {
            in = this->_stack.top();
            this->_stack.pop();
            for (i = in.getList().size() - 1; i >= 0; i--) {
                this->_stack.push(in.getList()[i]);
            }
        }
        in = this->_stack.top();
        this->_stack.pop();
        return in.getInteger();
    }

    bool hasNext() {
        return !this->_stack.empty();
    }

private:
    std::stack<NestedInteger> _stack;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */





