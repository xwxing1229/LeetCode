// https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n-1) {
            return -1;
        }

        int left = 1, right = dist[0];
        for (int d: dist) {
            right = max(right, d);
        }
        if (hour != (int)hour) {
            right = max(right, (int)((double)dist.back() / (hour-(int)hour))+1);
        }
        int res = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double total = 0;
            for (int i = 0; i < n-1; ++i) {
                double t = (double)dist[i] / mid;
                total += (int)t;
                if (t != (int)t) {
                    total += 1;
                }
            }
            total += (double)dist.back() / mid;
            if (total <= hour) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};
