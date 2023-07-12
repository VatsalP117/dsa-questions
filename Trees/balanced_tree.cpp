//brute force
int height(BinaryTreeNode<int>* node){
    if(node==NULL) return 0;
    if(node->left==NULL && node->right==NULL) return 1;
    else return 1+max(height(node->left),height(node->right));
}
//left and right both should be balanced and difference between their heights <=1
bool f(BinaryTreeNode<int>* node){
    if(node==NULL) return true;
    return f(node->left) && f(node->right) && (abs(height(node->left)-height(node->right))<=1);
    
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return f(root);
}


//optimal
//you are pre computing the height then checking again. why not just check when you are calculating height hi
//if balanced, just return height]
//if not return -1 saying not balanced
int height(TreeNode* node){
    if(node==NULL) return 0;
    int lh=height(node->left);
    int rh=height(node->right);
    if(lh==-1|| rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else return 1+max(lh,rh);
}

    bool isBalanced(TreeNode* root) {
        if(height(root)==-1) return false;
        else return true;
        
    }