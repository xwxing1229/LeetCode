// https://leetcode.cn/problems/heaters/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0, n = heaters.size();
        for (int h: houses) {
            if (h <= heaters[0]) {
                res = max(res, heaters[0] - h);
                continue;
            }
            else if (h >= heaters[n-1]) {
                res = max(res, h - heaters[n-1]);
                continue;
            }

            int left = 0, right = n-1, k = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] <= h) {
                    left = mid + 1;
                    k = mid;
                }
                else {
                    right = mid - 1;
                }
            }
            res = max(res, min(h-heaters[k], heaters[k+1]-h));
        }
        return res;
    }
};
