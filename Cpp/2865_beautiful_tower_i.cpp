// https://leetcode.cn/problems/beautiful-towers-i/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int cur = maxHeights[i];
            long long tmp = cur;
            // Left.
            for (int j = i-1; j >= 0; --j) {
                cur = min(cur, maxHeights[j]);
                tmp += cur;
            }
            // Right.
            cur = maxHeights[i];
            for (int j = i+1; j < n; ++j) {
                cur = min(cur, maxHeights[j]);
                tmp += cur;
            }
            res = max(res, tmp);
        }
        return res;
    }
};
