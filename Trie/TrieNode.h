#include<iostream>
using namespace std;

class TrieNode
{
  public:
    char data;
    TrieNode** children;
    bool isEnd;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
        isEnd = false;
    }

    void insert(char data)
    {
        this->children[data] = new TrieNode(data);
    }
};