// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int dfs(Node* root, int& ans){
        if (root==NULL)return 0;
        int lsum= dfs(root->left,ans);
        int rsum= dfs(root->right,ans);
        ans= max(ans,lsum+rsum+root->data);
        return max(0,root->data+max({lsum,rsum}));
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
