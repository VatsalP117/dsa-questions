//link:https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

#include <bits/stdc++.h> 
struct Node{
    Node* links[26]; //for all 26 character
    bool flag=false;

    //now define 2 imp methods as well
    bool containsKey(char ch){
        //links[ch-'a'] would be pointer to reference of that char
        //if null means it does not exist
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
private: Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    //insert is O(n) where n=length of word
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            //moves to the reference trie
            node=node->get(word[i]);
        }
        //once this ends, node will be at last reference trie
        node->setEnd();

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==false){
                return false;
            }
            //but if it does, move to that node
            node=node->get(word[i]);
        }
        //now at last reference which should have flag=true
        return node->isEnd();


    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(node->containsKey(prefix[i])==false){
                return false;
            }
            //but if it does, move to that node
            node=node->get(prefix[i]);
        }
        return true;

    }
     
};
bool checkValidAns(string &str,Trie trie){
        string temp="";
        for(int i=0;i<str.size();i++){
            temp+=str[i];
            if(trie.search(temp)==false){
                return false;
            }
        }
        return true;
    }
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto &it:a){
        trie.insert(it);
    }
    string longest="";
    for(auto &it:a){
        if(it.size()>=longest.size()){
            if(checkValidAns(it,trie)){
            if(it.size()>longest.size()){
                longest=it;
            }
            else if(it.size()==longest.size() && it<longest){
                longest=it;
            }
        }
        }
        
    }
    if(longest.size()==0){
        longest="None";
    }
    return longest;
}