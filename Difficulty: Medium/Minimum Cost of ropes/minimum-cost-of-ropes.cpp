class Solution {
public:
    int minCost(vector<int>& arr) {
        int count = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : arr)
            pq.push(it);

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            int total = first + second;
            pq.push(total);
            count += total;
        }
        return count;
    }
};