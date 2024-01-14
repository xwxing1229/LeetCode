// https://leetcode.cn/problems/remove-stones-to-minimize-the-total/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int pile: piles) {
            pq.push(pile);
        }
        for (int i = 0; i < k; ++i) {
            int pile = pq.top();
            pq.pop();
            pq.push((pile+1) / 2);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
