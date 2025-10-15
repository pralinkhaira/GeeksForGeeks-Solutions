//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int solve(Node *root, int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left=solve(root->left, ans);
        int right=solve(root->right, ans);
        
        ans+=abs(left)+abs(right);
        int extraCandies = root->data + left + right - 1;
        return extraCandies;
    }
    int distCandy(Node* root)
    {
        //code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
