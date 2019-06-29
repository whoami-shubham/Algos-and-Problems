#include<bits/stdc++.h>
using namespace std;
# define BEFORE 20   // space while print tree
# define AFTER  4

struct TreeNode{
   int val;
   TreeNode *left,*right;
   TreeNode(int v){
       val   = v;
       left  = NULL;
       right = NULL;  
   }
};


void Add_node(TreeNode** root,int val);  // function for add node in tree
void Print_tree(TreeNode* root);        //  function for print tree
string Serialize(TreeNode* root);
string Serialize_2(TreeNode* root);
TreeNode* DeSerialize(string s);
TreeNode* Construct_tree(queue<int>& nodes);  // function for construct tree while deserialization using level order traversal
TreeNode* Construct_tree_2(queue<int>& nodes);


int main(){

    TreeNode* root = NULL;
    Add_node(&root,1);
    Add_node(&root,2);
    Add_node(&root,3);
    Add_node(&root,4);
    Add_node(&root,5);
    Add_node(&root,6);
    Print_tree(root);
    cout<<endl;
    string serialized_tree = Serialize(root);
    cout<<"\n Serialized Tree :  "<<serialized_tree<<endl;
    cout<<" DeSerialized Tree "<<endl;
    TreeNode * deserialized_tree = DeSerialize(serialized_tree);
    Print_tree(deserialized_tree);

    return 0;
}

/*

Serialize() converts tree nodes into string sepearted by ',' so that we can construct tree again
from string. level order traversal is used in this implementation.

*/

string Serialize(TreeNode* root){
   if(!root){
       return "X";      // X represents NULL
   }
     string s = "";
     queue<TreeNode*>q;
     TreeNode *level_mark = new TreeNode(INT_MAX);
            q.push(root);
            q.push(level_mark);
            while(q.size()>0){
                TreeNode *temp = q.front();
                q.pop();
                if(temp){
                    if(temp->val != INT_MAX){
                        s = s + to_string(temp->val) + ',';
                        q.push(temp->left?temp->left:NULL);
                        q.push(temp->right?temp->right:NULL);
                    }
                    else{
                        if(q.size()>0){
                            q.push(level_mark);
                        }
                    }
                }
                else{
                   s = s + 'X'+',';
                }
            }
   return s;
}

string Serialize_2(TreeNode* root){
    if(!root){
        return "X";
    }
    string cur   = to_string(root->val);
    string left  = Serialize_2(root->left);
    string right = Serialize_2(root->right);
    return cur + ',' + left + ',' + right;
}


/*

Add_node() function uses level order traversal to insert node at appropriate place

*/

void Add_node(TreeNode** root,int val){
    TreeNode *temp = new TreeNode(val);
     if(!(*root)){
         *root = temp;
         return;
     }
     else{
            queue<TreeNode*>q;
            q.push(*root);
            TreeNode *prev = NULL;
            q.push(NULL);
            while(q.size()>0){
                TreeNode *cur = q.front();
                q.pop();
                if(cur){
                        if(!cur->left){
                            cur->left = temp;
                            return;
                        }
                        q.push(cur->left);
                        if(!cur->right){
                            cur->right = temp;
                            return;
                        }
                        q.push(cur->right);
                }
                else{
                    if(prev!=NULL){
                        q.push(NULL);
                    }
                }
                prev = cur;
            }
     }
}
/*
 Print_tree() also uses level order traversal to print tree one level at a time.

*/

void Print_tree(TreeNode* root){
    queue<TreeNode*>q;
    TreeNode *level_mark = new TreeNode(INT_MAX);
    int level = 0;
    int n1 = BEFORE;
    int n2 = AFTER;
    string after="";
    while(n2>0){
            after = after + " ";
            n2--;
        }
    q.push(root);
    q.push(level_mark);
    while(q.size()>0){
        string before="";
        n1 = max((BEFORE - 2*level),1);
        n2 = max((AFTER - 2*level-1),1);
        while(n1>0){
            before = before + " ";
            n1--;
        }
        TreeNode* temp = q.front();
        if(level==0){
            cout<<"   "<<before;
        }
        q.pop();
        if(temp){
            if(temp->val != INT_MAX){
                cout<<temp->val<<after;
                q.push(temp->left?temp->left:NULL);
                q.push(temp->right?temp->right:NULL);
            }
            else{
                if(q.size()>0){
                    level++;
                    cout<<"\n";
                    cout<<before;
                    q.push(level_mark);
                }
            }
        }
        else{
            cout<<"X "<<" ";
        }
    }
}

/*

store serialized tree into queue and after that construct tree

*/
TreeNode* DeSerialize(string s){
    queue<int>q;
    int i = 0, n = s.length();
    string cur = "";
    while(i<n){
      if(s[i]==','){
          if(cur.length()>0){
              q.push(atoi(cur.c_str()));
          }
          cur = "";
      }
      else if(s[i]!='X'){
          cur = cur + s[i];
      }
      else {
          cur = "";
          q.push(INT_MAX);
      }
      i++;
    }
    return Construct_tree(q);  // here when you're using Serialize() then use Construct_tree() and  
}                                // when you're using Serialize_2() then use Construct_tree_2()


TreeNode* Construct_tree(queue<int>& nodes){
    TreeNode *root = NULL;;
    if(nodes.size()==0 || nodes.front()==INT_MAX){
        return root;
    }
    queue<TreeNode**>q;
    q.push(&root);
    while(q.size()>0 && nodes.size()>0){

        TreeNode **temp = q.front();
        q.pop();
        int data = nodes.front();
        nodes.pop();
        if(data==INT_MAX){
            *temp = NULL;
        }
        else{
            *temp = new TreeNode(data);
            q.push(&(*temp)->left);
            q.push(&(*temp)->right);
        }
    }
    return root; 
}


TreeNode* Construct_tree_2(queue<int>& nodes){
    if(nodes.size()==0 || nodes.front()==INT_MAX){
        if(nodes.size()>0){
            nodes.pop();
        }
        return NULL;
    }
    TreeNode *root = new TreeNode(nodes.front());
    nodes.pop();
       root->left  = Construct_tree_2(nodes);
       root->right = Construct_tree_2(nodes);
    return root;
}
