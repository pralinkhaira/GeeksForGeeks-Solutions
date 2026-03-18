class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
    
private:
    int dfs(Node* node, int& moves) {
        if (!node) return 0;
        int left = dfs(node->left, moves);
        int right = dfs(node->right, moves);
        moves += abs(left) + abs(right);
        return node->data + left + right - 1;
    }
};