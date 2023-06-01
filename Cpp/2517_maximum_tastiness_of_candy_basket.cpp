// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int left = 0, right = price[n-1] - price[0];
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Try to find k candies such that their minimum difference
            // is >= mid.
            int pre = price[0], cnt = 1;
            for (int i = 1; i < n; ++i) {
                if (price[i] - pre >= mid) {
                    cnt += 1;
                    pre = price[i];
                }
            }

            if (cnt >= k) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
