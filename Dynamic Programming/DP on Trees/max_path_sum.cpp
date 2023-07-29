
//link: https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/
//max path sum from any node to any node

class Solution {
public:
    int solve(TreeNode* root,int &res){
        //base
        if(root==NULL) return 0;
        //hypothesis
        int l=max(0,solve(root->left,res));
        int r=max(0,solve(root->right,res));

        //induction
        //isko karta dharta(ans) nahi banna ye bas apni value aage dena chahta h ans nikalvane
        int temp=root->val+max(l,r);

        //ab isko bhi man to hoga na ki mai khud ans bann sakta hu kya(jaha se curve hoke vo path aayega to check kar lega)
        int ans=max(temp,root->val+l+r);
        res=max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};