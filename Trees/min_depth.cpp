//link: https://www.interviewbit.com/problems/min-depth-of-binary-tree/
//kinda weird but its tc is good
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void height(TreeNode* node,int curr_height,vector<int> &mini){
    if(node==NULL) return;
    if(node->left==NULL && node->right==NULL){
        mini[0]=min(mini[0],curr_height);
        return;
    }
    
    height(node->left,curr_height+1,mini);
    height(node->right,curr_height+1,mini);
}
int Solution::minDepth(TreeNode* A) {
    vector<int> mini(1,INT_MAX);
    if(A==NULL) return 0;
   height(A,1,mini);
    return mini[0];
}
//correct solution lmao
int Solution::minDepth(TreeNode* A) {
    if(A==NULL){return 0;}
    int l=minDepth(A->left);
    int r=minDepth(A->right);
    if(!l||!r){return max(l,r)+1;}
    return (1+min(l,r));
}