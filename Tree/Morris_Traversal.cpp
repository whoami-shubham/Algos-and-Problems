 /*
   Morris Traversal 

    for each node check if it's left exist or not 
    if left child exists then find inorder predecessor and connect it to current
    root and move current root to left  else 
    if left child doesn't exists or inorder predecessor of current root is itself
    than print or save current root value and if inorder predecessor is connected
    to current root then remove that link and move current root to right


 */
 vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur = root;
    while(cur){
            if(cur->left){
                TreeNode* prev = cur->left;
                while(prev->right && prev->right!=cur){ // find inorder predecessor
                    prev = prev->right;
                }
                if(!prev->right){       
                    prev->right = cur;
                    cur = cur->left;
                }
                else{                   
                    prev->right = NULL;    // remove link  
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
            else {
                ans.push_back(cur->val);
                cur = cur->right;       
           }
        }
        return ans;
    }