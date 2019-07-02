/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 **/

/*
 * in preorder  we have to traverse   root,left,right
 * 
 * in postorder we have to traverse   left,right,root which is reverse of
 * 
 *  reverse( root,right,left ) => left,right,root
 *
 */
vector<int> postorderTraversal(TreeNode* A) {
    
    vector<int>postorder;
    stack<TreeNode*>st;
    
    TreeNode* root = A;
    while(root || st.size()>0){
        
        while(root){
            st.push(root);
            postorder.push_back(root->val);
            root = root->right;
        }
        
        root = st.top();
        st.pop();
        root = root->left;
        
    }
    reverse(postorder.begin(),postorder.end());
    return postorder;
}
