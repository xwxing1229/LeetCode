// https://leetcode.cn/problems/teemo-attacking/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, start = timeSeries[0], end = timeSeries[0] + duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (end < timeSeries[i]) {
                res += (end - start);
                start = timeSeries[i];
            }
            end = timeSeries[i] + duration;
        }
        res += (end - start);
        return res;
    }
};
