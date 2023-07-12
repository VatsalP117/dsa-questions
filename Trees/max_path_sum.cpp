int f(TreeNode* node,vector<int> &maxi){
        //this function basically tells if am standing at a node, does left or right path give the max sum
        //vo max sum return karega
        if(node==NULL){
            return 0;
        }
        int leftPathSum=max(0,f(node->left,maxi));
        int rightPathSum=max(0,f(node->right,maxi));
        maxi[0]=max(maxi[0],node->val+ leftPathSum+rightPathSum);
        return node->val+ max(leftPathSum,rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        vector<int> maxi(1,INT_MIN);
        f(root,maxi);
        return maxi[0];
    }