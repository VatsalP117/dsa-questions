//link: https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
//instead of having flag=true/false, we will use 2 variables to count number of words

#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int cntEndWith=0;
    int cntPrefix=0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
     void increaseEnd() {
    cntEndWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void deleteEnd() {
    cntEndWith--;
  }
  void reducePrefix() {
    cntPrefix--;
  }
  int getEnd() {
    return cntEndWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};
class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==false){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();

        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
          Node* node=root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                }
                else{
                    return 0;
                }
            }
        return node->getPrefix();
        
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                    node->reducePrefix();
                }
                else{
                    return;
                }
            }
            node->deleteEnd();
    }
};
