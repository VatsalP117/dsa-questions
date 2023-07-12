//brute force(passing 103/104 cases)
int height(TreeNode* node){
    if(node==NULL) return 0;
    if(node->left==NULL && node->right==NULL) return 1;
    else return 1+max(height(node->left),height(node->right));
}
    int f(TreeNode* node){
        if(node==NULL) return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        return lh+rh;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return max(f(root),max(f(root->left),f(root->right)));

    }

//optimal
//again when calculating height itself iska hisaab rakhlo
int height(TreeNode* node,vector<int> &maxi){
    if(node==NULL) return 0;
    int lh=height(node->left,maxi);
    int rh=height(node->right,maxi);
    maxi[0]=max(maxi[0],lh+rh);
    return 1+max(lh,rh);
}
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> maxi(1,0);//since variables are not passed by reference so we pas vector
        height(root,maxi);
        return maxi[0];

    }