#include<iostream>
#include "TrieNode.h"
#include<string.h>
using namespace std;

class Trie
{
    TrieNode* root;

  public:
    Trie()
    {
        root = new TrieNode('\0');
    }

  private:
    void helpInsertWord(TrieNode* root,string word)
    {
        if(word.length()==0)
        {
            root->isEnd = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }

        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        helpInsertWord(child,word.substr(1));
    }

  public:
    void insertWord(string word)
    {
        helpInsertWord(root,word);
    }

  private:
    bool helpSearch(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            return root->isEnd;
        }

        int index = word[0] - 'a';

        if(root->children[index]!=NULL)
        {
            TrieNode* child = root->children[index];

            return helpSearch(child,word.substr(1));
        }

        return false;
    }

  public:
    bool search(string word)
    {
        return helpSearch(root,word);
    }

  private:
    void helpRemove(TrieNode* root,string word)
    {
        if(word.length()==0)
        {
            root->isEnd = false;

            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }

        else
        {
            return;
        }

        helpRemove(child,word.substr(1));

        if(child->isEnd==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                {
                    return;
                }
            }

            delete child;
            root->children[index] = NULL;
        }
    }

  public:
    void remove(string word)
    {
        helpRemove(root,word);
    }
};