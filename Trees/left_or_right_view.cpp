//1st approach: iterative
void printLeftView(BinaryTreeNode<int> *root)
{
    //Write your code here
    //ye bhi same jaisa hi hai vertical traversal jaisa
    //just maintain horizontal levels here
    //left and right will be at niche ka level

    //left view= first node of everyy level (same as top view connept)
    
    //right view=last node of every level (same as bottom view)
    //this is for left view
    vector<int> ans;
    if(root==NULL) return;
    queue<pair<int,BinaryTreeNode<int> *>> q;
    map<int,int> m;
    q.push({0,root});
    while(!q.empty()){
        int level=q.front().first;
        BinaryTreeNode<int> *node=q.front().second;
        q.pop();
        if(m.find(level)==m.end()){
            m[level]=node->data;
        }
        if(node->left!=NULL) {
            q.push({level+1,node->left});
            }
        if(node->right!=NULL){
            q.push({level+1,node->right});
        }
    }
    for(auto &it:m){
        cout<<it.second<<" ";
    }
    
}

//optimal (recursive)
//left view
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level){
            //encounter this level for first time
             res.push_back(root->val);
        }
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
        //right view chaiye to pehle call for node->right
    }
    
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};