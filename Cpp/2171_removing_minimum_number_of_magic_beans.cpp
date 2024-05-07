// https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long res = 0;
        int n = beans.size();
        vector<long long> cumsum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            int bean = beans[i];
            res += bean;
            cumsum[i+1] = cumsum[i] + bean;
        }
        for (int i = 0; i < n; ++i) {
            long long left = cumsum[i];
            long long right = cumsum[n] - cumsum[i] - (long long)(n-i)*beans[i];
            res = min(res, left+right);
        }
        return res;
    }
};