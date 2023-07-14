vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A==NULL) return ans;
    //preorder=ROOT LEFT RIGHT
    stack<TreeNode*> st;
    st.push(A);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        ans.push_back(node->val);
        //ulta of preorder coz left gaya baadme andar to bahar aayega pehle aur uske children daalgea vo sab bhi right ke pehle bahar
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);
    }
    return ans;
}