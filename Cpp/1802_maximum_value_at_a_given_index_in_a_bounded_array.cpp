// https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int res;
        int left = 1, right = maxSum;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int n_left = min(index+1, mid), n_right = min(n-index, mid);
            long sum_left = ((long)mid + max(1, mid-index)) * n_left / 2
                + index + 1 - n_left;
            long sum_right = ((long)mid + max(1, mid-n+index+1)) * n_right / 2
                + n - index - n_right;
            if (sum_left + sum_right - mid <= maxSum) {
                left = mid + 1;
                res = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
