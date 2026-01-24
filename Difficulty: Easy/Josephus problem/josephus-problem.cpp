class Solution {
public:
    int josephus(int n, int k) {
        // Using the mathematical recurrence relation
        // J(n, k) = (J(n-1, k) + k) % n
        // Base case: J(1, k) = 0 (0-indexed)
        
        int result = 0;
        for (int i = 2; i <= n; i++) {
            result = (result + k) % i;
        }
        
        // Convert from 0-indexed to 1-indexed
        return result + 1;
    }
};