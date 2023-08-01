//my code (thoda inefficent but passes all cases)
//offical solution bhi yahi hai to ig its efficent only 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::verticalSum(TreeNode* A) {
    vector<int> ans;
    if(A==NULL) return ans; //empty vector
    map<int,int> verticalSum; //{vertical,uska sum} sorted by vertical num
    queue<pair<int,TreeNode*>> q; //stores {vertical_num,node}
    q.push({0,A});
    
    //initialisation done
    while(!q.empty()){
        auto it=q.front();
        int level=it.first;
        TreeNode* node=it.second;
        verticalSum[level]+=node->val;
        q.pop();
        if(node->left!=NULL){
            q.push({level-1,node->left});
        }
        if(node->right!=NULL){
            q.push({level+1,node->right});
        }
    }
    //map ready with ans;
    for(auto it:verticalSum){
        ans.push_back(it.second);
    }
    return ans;
}
