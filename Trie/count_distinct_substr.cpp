//linK:https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};
class Trie {
private: Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==false){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==false){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(node->containsKey(prefix[i])==false){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
int countDistinctSubstrings(string &s)
{

    int n=s.size();
    int res=0;
    Trie trie;
    
    for(int i=0;i<n;i++){
        string sub="";
        for(int j=i;j<n;j++){
            sub+=s[j];
            if(trie.search(sub)==false){
                res++;
                trie.insert(sub);
            }
        }
    }
    //+1 coz we have to count empty substr as well
    return res+1;
}