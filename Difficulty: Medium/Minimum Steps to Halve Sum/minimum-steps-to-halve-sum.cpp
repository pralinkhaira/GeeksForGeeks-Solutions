class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double sum = 0;
        for (int it : arr) {
            pq.push(it);
            sum += it;
        }
        double req = sum / 2.0;
        int cnt = 0;
        while (sum > req) {
            double top = pq.top();
            pq.pop();
            sum -= top;
            top /= 2.0;
            sum += top;
            pq.push(top);
            cnt++;
        }
        return cnt;
    }
};