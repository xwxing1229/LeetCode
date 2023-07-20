// https://leetcode.cn/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> cumsum(2*n, 0);
        for (int i = 0; i < 2*n-1; ++i) {
            cumsum[i+1] = cumsum[i] + nums[i%n];
        }
        auto comp = [&](int i, int j) {
            return cumsum[i] > cumsum[j];
        };
        // Use a priority queue to save the indices such that
        // cumsum[pq.top()] <= cumsum[k] for any k in pq.
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 0; i < n; ++i) {
            pq.push(i);
        }
        int res = cumsum[n] - cumsum[pq.top()];
        for (int i = n; i < 2*n-1; ++i) {
            pq.push(i);
            while (pq.top() < i+1-n) {
                pq.pop();
            }
            res = max(res, cumsum[i+1] - cumsum[pq.top()]);
        }
        return res;
    }
};
