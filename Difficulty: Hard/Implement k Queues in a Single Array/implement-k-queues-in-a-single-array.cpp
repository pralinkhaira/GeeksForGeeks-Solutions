class kQueues {

  public:
    vector<queue<int>>queueArr;
    int cnt=0;
    int total = 0;
    kQueues(int n, int k) {
        cnt = n;
        queueArr.resize(k);
    }

    void enqueue(int x, int i) {
        total++;
        queueArr[i].push(x);
    }

    int dequeue(int i) {
        if(queueArr[i].size()==0) return -1;
        total--;
        int val = queueArr[i].front();
        queueArr[i].pop();
        return val;
    }

    bool isEmpty(int i) {
        return queueArr[i].empty();
    }

    bool isFull() {
        return total == cnt;
    }
};