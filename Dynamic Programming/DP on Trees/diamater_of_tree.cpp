    int solve(Node* root, int &res){
        //Base
        if(root==NULL) return 0;
        
        //Hypothesis
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        int temp=max(l,r)+1; //basically height of tree with this as root
        int ans=max(temp,l+r+1);//l+r+1 is diamter for path jo isse curve hoga
        res=max(res,ans);
        
        return temp;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int res=0;
        solve(root,res);
        return res;
    }