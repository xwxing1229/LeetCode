// https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> preSumArr(n+1, 0);
        for (int i = 0; i < n; ++i) {
            preSumArr[i+1] = preSumArr[i] + nums[i];
        }

        int res = n + 1;
        deque<int> q;
        for (int i = 0; i <= n; ++i) {
            while ((!q.empty()) && (preSumArr[i] - preSumArr[q.front()] >= k)) {
                int tmp = i - q.front();
                q.pop_front();
                if (tmp < res) {
                    res = tmp;
                }
            }
            while ((!q.empty()) && (preSumArr[q.back()] >= preSumArr[i])) {
                q.pop_back();
            }
            q.push_back(i);
        }

        if (res > n) {
            return -1;
        }
        return res;
    }
};
