// https://leetcode.cn/problems/maximal-score-after-applying-k-operations/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num: nums) {
            pq.push(num);
        }
        long long res = 0;
        for (int i = 0; i < k; ++i) {
            int num = pq.top();
            pq.pop();
            res += num;
            pq.push((num + 2) / 3);
        }
        return res;
    }
};