// https://leetcode.cn/problems/beautiful-towers-ii/
        
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();

        // left[i]: maximum index j s.t. j < i and maxHeights[j] <= maxHeights[i]
        vector<int> stk;
        vector<int> left(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && maxHeights[stk.back()] > maxHeights[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                left[i] = stk.back();
            }
            stk.push_back(i);
        }
        vector<long long> dp_left(n, 0);
        for (int i = 0; i < n; ++i) {
            long long h = maxHeights[i];
            if (i > 0 && h >= maxHeights[i-1]) {
                dp_left[i] = dp_left[i-1] + h;
            }
            else {
                int j = left[i];
                if (j > -1) {
                    dp_left[i] = dp_left[j] + h * (i-j);
                }
                else {
                    dp_left[i] = h * (i-j);
                }
            }
        }

        // right[i]: minimum index j s.t. j > i and maxHeights[j] < maxHeights[i]
        stk.clear();
        vector<int> right(n, n);
        for (int i = n-1; i >= 0; --i) {
            while (!stk.empty() && maxHeights[stk.back()] > maxHeights[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                right[i] = stk.back();
            }
            stk.push_back(i);
        }
        vector<long long> dp_right(n, 0);
        for (int i = n-1; i >= 0; --i) {
            long long h = maxHeights[i];
            if (i < n-1 && h >= maxHeights[i+1]) {
                dp_right[i] = dp_right[i+1] + h;
            }
            else {
                int j = right[i];
                if (j < n) {
                    dp_right[i] = dp_right[j] + h * (j-i);
                }
                else {
                    dp_right[i] = h * (j-i);
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dp_left[i] + dp_right[i] - maxHeights[i]);
        }
        return res;
    }
};