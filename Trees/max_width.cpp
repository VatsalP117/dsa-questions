//TWO VARIATIONS

//1ST VARIATION IS MAX NUMBER OF NODES IN A LEVEL
//LINK:https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_763671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int maxi=0;
    if(root==NULL) return maxi;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        maxi=max(maxi,size);
        for(int i=0;i<size;i++){
            TreeNode<int>*node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
    }
    return maxi;
}

//2ND VARIATION: https://leetcode.com/problems/maximum-width-of-binary-tree/
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.