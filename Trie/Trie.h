# pragma once

#include<iostream>
#include<bits/stdc++.h>

#define ALPHABETS 26
using namespace std;

struct TrieNode {
    vector<TrieNode*> *path;
    bool is_end;        // true , if a string ends here
    bool part_of_path;  // true, if this block lies in the path of a string 
    TrieNode(bool part = 0 , bool end = 0) {
        path = new vector<TrieNode*> (ALPHABETS, NULL);
        part_of_path = part;
        is_end = end;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie();
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
  };
