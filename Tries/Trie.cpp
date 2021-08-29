/* 
Efficient information retrieval data structure
Searches in optimal time O(key length) but uses extra storage

Insert a new Word O(word length)
Search for a given word O(word length)
*/

#include <array>
#include <iostream>

using namespace std;

//Defining Node Structure

class TrieNode
{
  public:
    bool ending;
    char letter;
    TrieNode*children[26];
    TrieNode(char c='\0')
    {
      this->ending=false;
      this->letter=c;
      for(int i=0;i<26;i++)
      {
        this->children[i]=NULL;
      }
    }
};

//Building Prefix Tree

class Trie{
  private:
    TrieNode*root;
    void print(TrieNode*root)
    {
      if(!root)return;
      cout<<root->letter<<" ";
      for(int i=0;i<26;i++)
      {
        print(root->children[i]);
      }
    }
  public:
    Trie(){
      root=new TrieNode();
    }
    
    void insertWord(string s)
    {
      TrieNode*temp=root;
      for(int i=0;i<s.length();i++)
      {
        int node=s[i]-'a';
        if(!temp->children[node])
        {
          temp->children[node]=new TrieNode(s[i]);
        }
        temp=temp->children[node];
      }
      temp->ending=true;
    }
    
    bool matchWord(string s)
    {
      TrieNode*temp=root;
      for(int i=0;i<s.length();i++)
      {
        int node=s[i]-'a';
        if(!temp->children[node])return false;
        temp=temp->children[node];
      }
      return temp->ending;
    }

    bool matchPrefix(string s)
    {
      TrieNode*temp=root;
      for(int i=0;i<s.length();i++)
      {
        int node=s[i]-'a';
        if(!temp->children[node])return false;
        temp=temp->children[node];
      }
      return true;
    }

    void printTree()
    {
      TrieNode*temp=root;
      print(temp);

    }

};

int main()
{
  Trie*t=new Trie();
   t->insertWord("chiru");
   t->insertWord("chia");
   t->printTree();
  return 0;
}
