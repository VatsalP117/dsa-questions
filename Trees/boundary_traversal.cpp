class Solution {
public:
    bool isLeaf(Node* node){
    if(node==NULL) return true;
    if(node->left==NULL && node->right==NULL) return true;
    else return false;
}
void addLeftBoundary(Node* node,vector<int> &res){
    if(node==NULL) return;
    Node* curr=node->left;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left!=NULL) curr=curr->left;
        else curr=curr->right;
    }
}
void addLeafNodes(Node* node,vector<int> &res){
    if(node==NULL) return;
    if(isLeaf(node)){
        res.push_back(node->data);
        return;
    }
    if(node->left!=NULL) addLeafNodes(node->left,res);
    if(node->right!=NULL) addLeafNodes(node->right,res);

}
void addRightBoundary(Node* node,vector<int> &res){
    if(node==NULL) return;
    vector<int> temp;
     Node* curr=node->right;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right!=NULL) curr=curr->right;
        else curr=curr->left;
    }
    //add in reverse
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
    
}
    vector <int> boundary(Node *root)
    {
        //Your code here
        // Write your code here.
    //approach
    //1st; all the left boundary excluding leaf nodes
    //2nd: leaf nodes (left to right inorder jaisa)
    //3rd: right boundary in reverse order
    vector<int> res;
    if(root==NULL) return res;
    res.push_back(root->data);
    if(isLeaf(root)) return res;
    addLeftBoundary(root,res);
    addLeafNodes(root,res);
    addRightBoundary(root,res);
    return res;
    }
};