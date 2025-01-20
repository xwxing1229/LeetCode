// https://leetcode.cn/problems/best-sightseeing-pair/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        // For j = 0, 1, ..., n-1,
        // right_max[j] = max(values[j]-j, values[j+1]-(j+1), ..., values[n-1]-(n-1)).
        vector<int> right_max(n, values.back()-(n-1));
        for (int j = n-2; j >= 0; --j) {
            right_max[j] = max(values[j]-j, right_max[j+1]);
        }
        int res = values[0] + 0 + right_max[1];
        for (int i = 0; i < n-1; ++i) {
            res = max(res, values[i] + i + right_max[i+1]);
        }
        return res;
    }
};
