//
// Created by nanji on 3/4/21.
// Trie 树前序遍历
//
#include "stdio.h"
#include "vector"
#include "string"

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode {
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;

    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = 0;
        }
    }
};

void preorder_trie(TrieNode *node, int layer) {
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i]) {
            for (int j = 0; j < layer; j++) {
                printf("---");
            }
            printf("%c", i + 'a');
            if (node->child[i]->is_end) {
                printf("(end)");
            }
            printf("\n");
            preorder_trie(node->child[i], layer + 1);
        }
    }
}

void get_all_word_from_trie(TrieNode *node,
                            std::string &word,
                            std::vector<std::string> &word_list) {
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i]) {
            word.push_back('a');
            if (node->child[i]->is_end) {
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i], word, word_list);
            word.erase(word.length() - 1, 1);
        } //弹出栈顶字符

    }
}

class TrieTree {

public:
    TrieTree() {}

    ~TrieTree() {
        for (int i = 0; i < _node_vec.size(); i++) {
            delete _node_vec[i];
        }
    }

    void insert(const char *word) {

    }

    bool search(const char *word) {

    }

    bool startsWith(const char *prefix) {

    }

    TrieNode *root() {
        return &_root;
    }

private:
    std::vector<TrieNode *> _node_vec;
    TrieNode _root;

    TrieNode *new_node() {
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }


};

int main() {
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['e' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n2.is_end = true;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;
    n11.is_end = true;

//    preorder_trie(&root, 1);

    std::vector<std::string> wordlist;
    std::string word;
    get_all_word_from_trie(&root, word, wordlist);
    for (int i = 0; i < wordlist.size(); i++) {
        printf("%s\n", wordlist[i]);
    }
    return 0;
}
