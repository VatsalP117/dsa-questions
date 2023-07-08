vector<vector<int>> levelOrder(TreeNode* root) {
      
      queue<TreeNode*> q;
      vector<vector<int>> ans;
      if(root==NULL) return ans;
      q.push(root);
      while(!q.empty()){
          int size=q.size(); //all elements of a level in the queue at a given time
          //so remove all of them together and put the next level inside
          vector<int> level;
          for(int i=0;i<size;i++){
              TreeNode* node=q.front();
              level.push_back(node->val);
              q.pop();
              
              if(node->left!=NULL) q.push(node->left);
              if(node->right!=NULL) q.push(node->right);
          }
          ans.push_back(level);
      }
      return ans;
    }