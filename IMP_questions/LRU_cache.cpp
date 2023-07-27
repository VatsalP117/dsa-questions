//link: https://leetcode.com/problems/lru-cache/submissions/
//best explaination: https://www.youtube.com/watch?v=Xc4sICC8m4M

Idea: use a DLL and hashmap. most recent used nodes are near head and least usedare near tail 
so delete from tail and insert at head (when you get also delete node and insert at head )

class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int k,int v){
        key=k;
        val=v;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    int size;
    unordered_map<int,Node*> um;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void deleteNode(Node* x){
        if(x==NULL) return;
        Node* prevNode=x->prev;
        Node* nextNode=x->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        
    }
    void addNode(Node* x){
        Node* nextNode=head->next;
        head->next=x;
        x->prev=head;
        x->next=nextNode;
        nextNode->prev=x;
    }
    int get(int key) {
        if(um.find(key)!=um.end()){
            Node* resNode=um[key];
            int res_ans=resNode->val;
            um.erase(key);
            deleteNode(resNode);
            Node* new1=new Node(key,res_ans);
            addNode(new1);
            um[key]=new1;
            return res_ans;
        }
        return -1;
    }
    
    void put(int key1, int value1) {
        if(um.find(key1)!=um.end()){
            Node* x=um[key1];
            um.erase(key1);
            deleteNode(x);
            size--;
        }
        if(size==cap){
            //delete least recently used jo
            um.erase(tail->prev->key);
            deleteNode(tail->prev);
            size--;
        }

        //now add new node
        Node * new1=new Node(key1,value1);
        addNode(new1);
        um[key1]=new1;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */