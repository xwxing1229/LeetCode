// https://leetcode.cn/problems/take-gifts-from-the-richest-pile/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int gift: gifts) {
            pq.push(gift);
        }
        for (int i = 0; i < k; ++i) {
            int gift = pq.top();
            pq.pop();
            pq.push(sqrt(gift));
        }
        long long res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};