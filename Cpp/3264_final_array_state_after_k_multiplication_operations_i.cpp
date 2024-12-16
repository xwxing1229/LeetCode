// https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i/

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        using pi = pair<int, int>;

        int n = nums.size();
        priority_queue<pi> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(-nums[i], -i));
        }
        for (int step = 0; step < k; ++step) {
            pi num_idx = pq.top();
            pq.pop();
            pq.push(make_pair(num_idx.first * multiplier, num_idx.second));
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            pi num_idx = pq.top();
            pq.pop();
            res[-num_idx.second] = -num_idx.first;
        }
        return res;
    }
};
