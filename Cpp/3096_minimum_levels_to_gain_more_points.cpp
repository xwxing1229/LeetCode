// https://leetcode.cn/problems/minimum-levels-to-gain-more-points/

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> cumsum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cumsum[i+1] = cumsum[i] + 2 * possible[i] - 1;
        }
        int total = cumsum.back();
        for (int i = 1; i < n; ++i) {
            if (cumsum[i] > total - cumsum[i]) {
                return i;
            }
        }
        return -1;
    }
};

