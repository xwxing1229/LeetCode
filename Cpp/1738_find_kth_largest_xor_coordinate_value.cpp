// https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> values(m, vector<int>(n, matrix[0][0]));
        priority_queue<int> pq;
        pq.push(matrix[0][0]);
        for (int j = 1; j < n; ++j) {
            values[0][j] = (values[0][j-1] ^ matrix[0][j]);
            pq.push(values[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            values[i][0] = (values[i-1][0] ^ matrix[i][0]);
            pq.push(values[i][0]);
            int row_xor = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                row_xor = (row_xor ^ matrix[i][j]);
                values[i][j] = (values[i-1][j] ^ row_xor);
                pq.push(values[i][j]);
            }
        }

        for (int i = 0; i < k-1; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};
