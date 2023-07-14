bool f(Node* node){
    if(node==NULL) return true;
    if(node->left==NULL && node->right==NULL) return true;
    int l=(node->left)?node->left->data:0;
    int r=(node->right)?node->right->data:0;
    return node->data==(l+r) && f(node->left) && f(node->right);

}
bool isParentSum(Node *root){
    // Write your code here.
    return f(root);
}