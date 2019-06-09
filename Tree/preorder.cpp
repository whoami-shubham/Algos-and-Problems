/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> preorderTraversal(TreeNode* A) {
    vector<int>preorder;
    stack<TreeNode*>st;
    TreeNode* root = A;
    
    while(root || st.size()>0){
        while(root){
            st.push(root);
            preorder.push_back(root->val);
            root = root->left;
        }
        root = st.top();
        st.pop();
        root = root->right;
    }
    return preorder;
}
