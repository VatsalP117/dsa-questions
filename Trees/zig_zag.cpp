//my code (thoda brute)
#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    queue<TreeNode<int>*> q;
    vector<int> ans;
    if(root==NULL) return ans;
    q.push(root);
    int reverse_kare_kya=0;
    while(!q.empty()){
        int size=q.size(); //number of elements in queue= number of elements in that level
        int arr[size];
        
        for(int i=0;i<size;i++){
            TreeNode<int> *node=q.front();
            q.pop();
            arr[i]=node->data;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);

        }
        if(reverse_kare_kya==0){
            for(int i=0;i<size;i++){
                ans.push_back(arr[i]);
            }
        }
        else{
            for(int i=size-1;i--;i>=0){
                ans.push_back(arr[i]);
            }
        
        }
        if(reverse_kare_kya==0) reverse_kare_kya=1;
        else reverse_kare_kya=0;
    }
    return ans;
}

