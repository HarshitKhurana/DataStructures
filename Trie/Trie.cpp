
#include"Trie.h"

    Trie::Trie() {
        root = new TrieNode();
        root->part_of_path = 1;
    }

     /** Inserts a word into the trie. */
    void Trie::insert(string word) {
        TrieNode *curr_node = root;
        int n = word.size();
        for (int i = 0 ; i < n; i ++) {
            char ch = word[i];
            int index = ch - 'a';
            if (curr_node->path->at(index) == NULL)
                curr_node->path->at(index) = new TrieNode();
            curr_node->path->at(index)->part_of_path = 1;
            if ( i == n-1)
                curr_node->path->at(index)->is_end = 1;
            curr_node = curr_node->path->at(index);
        }
        return;
    }

    /** Returns if the word is in the trie. */
    bool Trie::search(string word) {
        TrieNode *curr_node = root;
        int n = word.size();
        for (int i = 0 ; i < n ; i ++) {
            char ch = word[i];
            int index = ch - 'a';
            if (curr_node->path->at(index) == NULL)
                return false;
            if ( !curr_node->path->at(index)->part_of_path)
                return false;
            if ( i == n-1)
                return curr_node->path->at(index)->is_end;
            curr_node = curr_node->path->at(index);
        }
        return false;    // won't ever reach here
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool Trie::startsWith(string prefix) {
        TrieNode *curr_node = root;
        for (char ch: prefix) {
            int index = ch - 'a';
            if (curr_node->path->at(index) == NULL)
                return false;
            if ( !curr_node->path->at(index)->part_of_path)
                return false;
            curr_node = curr_node->path->at(index);
        }
        return true;
    }
 
