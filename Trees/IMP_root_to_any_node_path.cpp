//https://www.interviewbit.com/problems/path-to-given-node/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool getPath(TreeNode* node,vector<int> &path,int x){
     if(node==NULL)return false;
     path.push_back(node->val);
     if(node->val==x) return true;
     if(getPath(node->left,path,x) || getPath(node->right,path,x)) return true;
     
     //yaha tak pahoch gaye matlab ye raaste pe path nahi hai milega go back 
     path.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    if(A==NULL) return path;
    getPath(A,path,B);
    return path;
}