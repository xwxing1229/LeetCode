// https://leetcode.cn/problems/reducing-dishes/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> cumsum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cumsum[i+1] = cumsum[i] + satisfaction[i];
            res += (i+1) * satisfaction[i];
        }
        int tmp = res;
        for (int i = 0; i < n; ++i) {
            tmp -= cumsum[n] - cumsum[i];
            res = max(res, tmp);
        }
        return res;
    }
};
