class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int size = n * n;

        // jump[x] = destination of ladder/snake from x
        vector<int> jump(size + 1, 0);

        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        vector<bool> visited(size + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int throws = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                int curr = q.front();
                q.pop();

                if (curr == size)
                    return throws;

                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;

                    if (next > size)
                        break;

                    // Take ladder or snake
                    if (jump[next] != 0)
                        next = jump[next];

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            throws++;
        }

        return -1;
    }
};

