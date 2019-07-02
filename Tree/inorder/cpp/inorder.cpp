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

vector<int> inorderTraversal(TreeNode* A) {
    
    vector<int>inorder;
    stack<TreeNode*>st;
    TreeNode* root = A;

    while(st.size()>0 || root){
          while(root){
              st.push(root);
              root = root->left;
          }
          root = st.top();
          st.pop();
          inorder.push_back(root->val);
          root = root->right;
          
    }
    return inorder;
}
