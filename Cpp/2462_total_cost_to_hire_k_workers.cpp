// https://leetcode.cn/problems/total-cost-to-hire-k-workers/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int left = 0, right = costs.size()-1;
        while (left <= right && pq.size() != 2*candidates) {
            pq.push(make_pair(costs[left], left));
            left += 1;
            if (left > right) {
                break;
            }
            pq.push(make_pair(costs[right], right));
            right -= 1;
        }
        long long res = 0;
        for (int i = 0; i < k; ++i) {
            auto cost_idx = pq.top();
            pq.pop();
            res += cost_idx.first;
            if (cost_idx.second < left && left <= right) {
                pq.push(make_pair(costs[left], left));
                left += 1;
            }
            else if (cost_idx.second > right && left <= right) {
                pq.push(make_pair(costs[right], right));
                right -= 1;
            }
        }
        return res;
    }
};
