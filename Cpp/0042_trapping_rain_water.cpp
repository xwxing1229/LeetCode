// https://leetcode.cn/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_left(n, 0), max_right(n, 0);
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i-1], height[i-1]);
        }
        for (int i = n-2; i >= 0; --i) {
            max_right[i] = max(max_right[i+1], height[i+1]);
        }
        int res = 0;
        for (int i = 1; i < n-1; ++i) {
            int h = min(max_left[i], max_right[i]);
            if (h > height[i]) {
                res += h - height[i];
            }
        }
        return res;
    }
};
