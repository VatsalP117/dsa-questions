bool f(BinaryTreeNode<int>* node1, BinaryTreeNode<int>* node2){
    if(node1==NULL && node2==NULL) return true;
    if(node1==NULL || node2==NULL) return false;
    return (node1->data==node2->data) && f(node1->left,node2->left) && f(node1->right,node2->right);
}
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    return f(root1,root2);
}