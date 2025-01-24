// https://leetcode.cn/problems/node-with-highest-edge-score/

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long> cnts(n, 0);
        for (int i = 0; i < n; ++i) {
            cnts[edges[i]] += i;
        }
        int res = 0;
        long cnt_max = cnts[0];
        for (int i = 0; i < n; ++i) {
            if (cnts[i] > cnt_max) {
                res = i;
                cnt_max = cnts[i];
            }
        }
        return res;
    }
};
