//max path sum from leaf to leaf node
//https://www.codingninjas.com/studio/problems/maximum-path-sum-between-two-leaves_794950?leftPanelTab=1

Pehle vo max(0,l) sab tha ki mere left/right subtree se negative aa raha sirf meri value le lo fayda hoga 
ab aisa nahi kar sakte sirf leaf node hi aisa bol sakta h
also if only 1 leaf node return -1 as specified by question
long long solve(TreeNode<int>* root,int &res,int &count){
        //base
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            count=count+1;
            return root->val;
        }
        //hypothesis
        int l=solve(root->left,res,count);
        int r=solve(root->right,res,count);

        //induction
        //isko karta dharta(ans) nahi banna ye bas apni value aage dena chahta h ans nikalvane
        int temp=root->val+max(l,r);

        //ab isko bhi man to hoga na ki mai khud ans bann sakta hu kya(jaha se curve hoke vo path aayega to check kar lega)
        int ans=max(temp,root->val+l+r);
        res=max(res,ans);
        return temp;
    }
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    int res=INT_MIN;
    int count=0;
    solve(root,res,count);
    if(count<=1) return -1;
    return res;
}