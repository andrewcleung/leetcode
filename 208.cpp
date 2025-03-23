#include <iostream>
#include <string>
#include <array>
#include <bitset>

using namespace std;


class Trie
{
private:
    struct Node{
        array<Node*, 26> child;
        bool isWord = false;
    };
public:
    Node* root;

    Trie()
    {
        root = new Node();
    }


    void insert(string word)
    {
        Node *curr = root;
        for (auto c: word){
            if (!curr->child[c-'a']){
                curr->child[c - 'a'] = new Node();
            }
            curr = curr->child[c-'a'];
        }
        curr->isWord = true;
    }

    bool search(string word)
    {
        Node *curr = root;
        for (auto c: word) {
            if (!curr->child[c-'a']) return false;
            curr = curr->child[c-'a'];
        }
        return curr->isWord;
    }

    bool startsWith(string prefix)
    {
        
        Node *curr = root;
        for (auto c: prefix) {
            if (!curr->child[c-'a']) return false;
            curr = curr->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char **argv)
{
    return 0;
}