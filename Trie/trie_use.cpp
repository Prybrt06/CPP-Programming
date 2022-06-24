#include<iostream>
#include "Trie.h"
using namespace std;

int main()
{
    Trie* ourTrie = new Trie();

    ourTrie->insertWord("the");                                     // "the" is inserted
    ourTrie->insertWord("this");                                    // "this" is inserted
    ourTrie->insertWord("there");                                   // "there" is inserted

    cout << "the :" << ourTrie->search("the") << endl;              // "the" is present
    cout << "these :" << ourTrie->search("these") << endl;          // "these" is not present

    ourTrie->remove("the");                                         // "the" is removed

    cout << "the :" << ourTrie->search("the") << endl;              // "the" is not present
    cout << "these :" << ourTrie->search("these") << endl;          // "these" is not present
    cout << "there :" << ourTrie->search("there") << endl;          // "there" is present

    return 0;
}