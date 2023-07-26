//not optimal (using path to any node)

 bool getPath(TreeNode<int>* node,vector<int> &path,int x){
     if(node==NULL)return false;
     path.push_back(node->data);
     if(node->data==x) return true;
     if(getPath(node->left,path,x) || getPath(node->right,path,x)) return true;
     
     //yaha tak pahoch gaye matlab ye raaste pe path nahi hai milega go back 
     path.pop_back();
     return false;
 }
vector<int> getPath(TreeNode<int>* A, int B) {
    vector<int> path;
    if(A==NULL) return path;
    getPath(A,path,B);
    return path;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    vector<int> pathToX=getPath(root, x);
    vector<int> pathToY=getPath(root, y);


	int index;

	//    Iterate while elements in the lists are equal.
	for (index = 0; index < min(pathToX.size(), pathToY.size()); index++)
	{
		if (pathToX[index] != pathToY[index])
		{
			//    Elements are not same.
			break;
		}
	}

	//    Return the LCA.
	return pathToX[index - 1];
}



//optimal
PS:- You will be given a two nodes and you need to return LCA of those two nodes. 

Solution approach:- Use DFS traversal(Recursive DFS) first go to left and then go to right. 
0) If the root node is only one the node which you are looking for then return root
1) If both left and right returns null then returns null
2) If left returns a node and right returns null then return left and vice versa (Return something which gives u node) 
3) If both returns you the nodes then u have found the answer so return root


int f(TreeNode<int> *node, int x, int y){
    if(node==NULL) return -1;
    //if -1 means not found anything
    else if (node->data == x || node->data == y)
	{
		//   The root node itself will be the LCA.
		return node->data;
	}
    else if(f(node->left,x,y)!=-1 && f(node->right,x,y)!=-1) return node->data;
   
    else return max(f(node->left,x,y),f(node->right,x,y));
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return f(root,x,y);
}