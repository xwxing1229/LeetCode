// https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1000000007;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int h_max = horizontalCuts[0], v_max = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            h_max = max(h_max, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        h_max = max(h_max, h - horizontalCuts.back());
        for (int i = 1; i < verticalCuts.size(); ++i) {
            v_max = max(v_max, verticalCuts[i] - verticalCuts[i-1]);
        }
        v_max = max(v_max, w - verticalCuts.back());
        return ((long long)h_max * v_max) % mod;
    }
};