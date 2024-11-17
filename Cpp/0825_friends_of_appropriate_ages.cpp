// https://leetcode.cn/problems/friends-of-appropriate-ages/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0, n = ages.size();
        sort(ages.begin(), ages.end());
        for (int i = 0; i < n; ++i) {
            int x = ages[i], valid_min = 0.5 * x + 7;
            if (x < 15) continue;

            int left = 0, right = i-1, idx_min = i;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (ages[mid] <= valid_min) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                    idx_min = mid;
                }
            }

            left = i+1;
            right = n-1;
            int idx_max = i;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (ages[mid] <= x) {
                    left = mid + 1;
                    idx_max = mid;
                }
                else {
                    right = mid - 1;
                }
            }

            res += idx_max - idx_min;
        }
        return res;
    }
};
