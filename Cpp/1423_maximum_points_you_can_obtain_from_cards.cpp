// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window = 0, total = 0;
        int window_len = n-k;
        for (int i = 0; i < window_len; ++i) {
            window += cardPoints[i];
            total += cardPoints[i];
        }
        int window_min = window;
        for (int i = window_len; i < n; ++i) {
            window += cardPoints[i] - cardPoints[i-window_len];
            window_min = min(window, window_min);
            total += cardPoints[i];
        }
        return total - window_min;
    }
};