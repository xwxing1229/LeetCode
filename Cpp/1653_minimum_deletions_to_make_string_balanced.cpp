// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> cnt_left_b(n), cnt_right_a(n);
        for (int i = 1; i < n; ++i) {
            // Count how many bs on the left side of the current position.
            cnt_left_b[i] = cnt_left_b[i-1] + s[i-1] - 'a';
            /* The following way may be slower.
            if (s[i-1] == 'b') {
                cnt_left_b[i] = cnt_left_b[i-1] + 1;
            }
            else {
                cnt_left_b[i] = cnt_left_b[i-1];
            } */

            // Count how many as on the right side of the current position.
            cnt_right_a[n-i-1] = cnt_right_a[n-i] + 1 - (s[n-i] - 'a');
            /* The following way may be slower.
            if (s[n-i] == 'a') {
                cnt_right_a[n-i-1] = cnt_right_a[n-i] + 1;
            }
            else {
                cnt_right_a[n-i-1] = cnt_right_a[n-i];
            } */
        }
        int res = n;
        for (int i = 0; i < n; ++i) {
            int tmp = cnt_left_b[i] + cnt_right_a[i];
            if (tmp < res) {
                res = tmp;
            }
        }
        return res;
    }
};
