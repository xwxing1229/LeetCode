// https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [&](const pair<int,int>& p1, const pair<int,int>& p2) {
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };

        int rows = matrix.size(), cols = matrix[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < rows; ++i) {
            pq.push(make_pair(i, 0));
        }

        for (int step = 1; step < k; ++step) {
            pair<int,int> idxs = pq.top();
            pq.pop();
            if (idxs.second + 1 < cols) {
                pq.push(make_pair(idxs.first, idxs.second+1));
            }
        }
        int res = matrix[pq.top().first][pq.top().second];
        return res;
    }
};
