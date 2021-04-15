//
// Created by nanji on 4/14/21.
//
/**
 * Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

示例：

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
typedef struct tNode {
    tNode *next[26];
    bool end = 1;
} tNode;

#include "string"

class Trie {
private:
    tNode root;
public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < 26; i++) {
            this->root.next[i] = NULL;
        }
        this->root.end = 1;
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        tNode *next = &root;
        tNode *tmp = NULL;
        for (int i = 0; i < word.length(); i++) {
            if (!next->next[word[i] - 'a']) {
//                next->end = 0;
                tNode *tmp = new tNode();
                next->next[word[i] - 'a'] = tmp;
                next = tmp;
                tmp->end = 0;
            } else {
                next = next->next[word[i] - 'a'];
            }
        }
        next->end = 1;

    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        tNode *next = &this->root;
        for (int i = 0; i < word.length(); i++) {
            if (!next->next[word[i] - 'a']) {
                return false;
            }
            next = next->next[word[i] - 'a'];
        }
        return next->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        tNode *next = &this->root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!next->next[prefix[i] - 'a']) {
                return false;
            }
            next = next->next[prefix[i] - 'a'];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
//    t.insert("app");
    bool result = t.search("appa");
//    bool result = t.search("app");
//    result = t.search("app");
//    result = t.startsWith("app");
    printf("%d\n", result);
    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
