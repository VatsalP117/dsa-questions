//WRONG LOGIC; LEVEL ORDER TRAVESE AND CHECK IF EACH LEVEL IS A PALINDROME BASICALLY
//NAHI CHALEGA COZ LEFT MAI EK SUBTREE MAI EK MAI RIGHT AUR MIRROR MAI IMAGE SAM ENAHI AAYEGA

//CORRECT THINKING IS;
//at every node uske niche left and right mai sam echize deikhni chaiye usko exact
//since mirro mai left right ho jayega and vice versa
//so left should be == right for it be symmetric

//basically: left node ka right ==right node ka left
//left node ka left==righ node ka right
bool isSymmetricHelp(BinaryTreeNode<int>* node1,BinaryTreeNode<int>* node2){
    if(node1==NULL || node2==NULL){
        return node1==node2;
    }
    if(node1->data!=node2->data) return false;
    return isSymmetricHelp(node1->left,node2->right) && isSymmetricHelp(node1->right,node2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root) {
	//Write your code here
    if(root==NULL) return true;
    return isSymmetricHelp(root->left,root->right);
}


//SUMMARY
Self Notes: 
💡 Mirror property is  left == right and right == left
💡 pre-order traversal on root->left subtree, (root, left, right)
💡 modified pre-order traversal on root->right subtree, (root, right, left) 
💡 compare the node val's if they are the same 
💡 Do both traversals at the same time
💡 if left is null or right is null, then both sides must match and return true (base case)