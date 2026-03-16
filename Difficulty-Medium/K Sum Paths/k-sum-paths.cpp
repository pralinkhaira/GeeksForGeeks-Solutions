class Solution {
public:
    int countAllPaths(Node* root, int k) {
        unordered_map<long long, int> prefixSum{{0, 1}};
        return dfs(root, k, 0, prefixSum);
    }
    
private:
    int dfs(Node* node, int k, long long sum, unordered_map<long long, int>& mp) {
        if (!node) return 0;
        
        sum += node->data;
        int count = mp[sum - k];
        
        mp[sum]++;
        count += dfs(node->left, k, sum, mp);
        count += dfs(node->right, k, sum, mp);
        mp[sum]--;
        
        return count;
    }
};