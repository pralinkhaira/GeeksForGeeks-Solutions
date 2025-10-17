class Solution {
  private:
    void inorder(Node* root,vector<int>&v,bool flag,map<int,int>&mp){
        if(root == nullptr) return;
        
        inorder(root->left,v,flag,mp);
        
        if(flag){
            root->data = mp[root->data];
        }
        else{
            v.push_back(root->data);
        }
        
        inorder(root->right,v,flag,mp);
    }
  public:
    void transformTree(Node *root) {
        // code here
        vector<int>v;
        map<int,int>mp;
        
        inorder(root,v,0,mp);
        
        
        int n = v.size();
        
        int sum = 0;
        for(int i=n-1;i>=0;i--){
            mp[v[i]] = sum;
            sum += v[i];
        }
        
        inorder(root,v,1,mp);
        
    }
};