
// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    pair<int,int> solve(Node *root){
        if(!root){
            return {0,0};
        }
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        
        int include = root->data + l.second + r.second;
        int exclude = max(l.first,l.second) + max(r.first,r.second);
        
        return {include,exclude};
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
        
    }
};
