class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        if(root==NULL){
            return NULL;
        }
        if(root->data<l){
            return removekeys(root->right,l,r);
        }
        if(root->data>r){
            return removekeys(root->left,l,r);
        }
        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        return root;
    }
};