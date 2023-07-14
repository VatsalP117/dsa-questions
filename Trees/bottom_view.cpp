
//same code as top_view
//bas always change value of map[level] since you will always have next node at lower horizontal level
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
        vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<int,BinaryTreeNode<int>*>> q;
    map<int,int> m;
    q.push({0,root});
    while(!q.empty()){
        int level=q.front().first;
        BinaryTreeNode<int>* node=q.front().second;
        q.pop();
        
            //we found the first element of this level!
            m[level]=node->data;
           
        
        if(node->left!=NULL){
            q.push({level-1,node->left});
        }
        if(node->right!=NULL){
            q.push({level+1,node->right});
        }
    }
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
    
}

