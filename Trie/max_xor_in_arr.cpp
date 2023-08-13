//link: https://www.codingninjas.com/studio/problems/maximum-xor_3119012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
//approach explained in max_xor_val file

struct Node{
    Node* links[2];//since only 0 or 1
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
};
class Trie{
    private:Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i) & 1;
                if(node->containsKey(bit)==false){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int getMax(int num){
            Node* node=root;
            int maxNum=0;
            //return max xor with num value
            for(int i=31;i>=0;i--){
                int bit=(num>>i) & 1;
                if(node->containsKey(1-bit)){
                    //make this bit in our res=1
                    maxNum=maxNum | (1<<i);
                    node=node->get(1-bit);
                }
                else{
                    //bit still says as zero
                    node=node->get(bit);
                }
            }
            return maxNum;
        }
};
int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie trie;
    for(int num:A){
        trie.insert(num);
    }
    int res=0;
    for(int num:A){
        res=max(res,trie.getMax(num));
    }
    return res;
}