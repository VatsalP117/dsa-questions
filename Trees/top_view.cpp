vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<int,TreeNode<int>*>>> q;
    map<int,int> m;
    q.push({0,root});
    while(!q.empty()){
        int level=q.front().first;
        TreeNode<int>* node=q.front().second;
        q.pop();
        if(m.find(level)==m.end()){
            //we found the first element of this level!
            m[level]=node->val;
           
        }
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