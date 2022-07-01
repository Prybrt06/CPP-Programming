#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    bool helpSearch(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            return true;
        }

        int index = word[0] - 'a';

        if(root->children[index]!=NULL)
        {
            TrieNode* child = root->children[index];

            return helpSearch(child,word.substr(1));
        }

        return false;
    }
    
    void printChild(TrieNode *root,string *pattern)
    {
        string ans = *pattern;
        
        if(pattern->length()==0)
        {
            // cout << ans;
            // ans = "";
            return;
        }
        
        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
            {
                TrieNode *child = root->children[i];
                ans += child->data;
                cout << ans << endl;
                printChild(root,&ans);
            }
        }
    }

  public:
    bool search(string word)
    {
        return helpSearch(root,word);
    }
    
    void getSuggestion(vector<string> &temp,TrieNode *root,string pattern)
    {
        if(root->isTerminal)
        {
            temp.push_back(pattern);
        }
        
        for(char ch = 'a'; ch <= 'z';ch++)
        {
            TrieNode *next = root->children[ch - 'a'];
            
            if(next != NULL)
            {
                pattern.push_back(ch);
                getSuggestion(temp,next,pattern);
                pattern.pop_back();
            }
        }
    }
    
    void autoComplete(TrieNode *root,vector<string> input, string pattern)
    {
        int i = 0;
        while(!input.empty())
        {
            insertWord(input[i]);
            i++;
            input.pop_back();
        }
        
        bool check = search(pattern);
        
        if(!check)
        {
            return;
        }
        
        TrieNode *child = root;
        for(int i=0;i<pattern.length();i++)
        {
            char lastChar = pattern[i];
            
            child = child->children[lastChar - 'a'];
        }

        vector<string> temp;
        getSuggestion(temp,child,pattern);
        
        int j = 0;
        while(!temp.empty())
        {
            cout<< temp[j] << endl;
            temp.pop_back();

            j++;
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        autoComplete(root,input,pattern);
    }
};





int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}