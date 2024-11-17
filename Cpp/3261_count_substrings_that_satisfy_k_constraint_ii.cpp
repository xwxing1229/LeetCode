// https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int i = 0, n = s.size();
        vector<int> valid(n, 0), cnt(2, 0);
        vector<long long> cumsum(n+1, 0);
        for (int j = 0; j < n; ++j) {
            cnt[s[j] - '0'] += 1;
            while (cnt[0] > k && cnt[1] > k && i <= j) {
                cnt[s[i] - '0'] -= 1;
                i += 1;
            }
            valid[j] = i;
            cumsum[j+1] = cumsum[j] + j - i + 1;
        }

        vector<long long> res(queries.size(), 0);
        for (int idx = 0; idx < queries.size(); ++idx) {
            int ql = queries[idx][0], qr = queries[idx][1];
            // Find the maximum j such that valid[j] <= ql.
            int a = ql, b = qr, j = ql;
            while (a <= b) {
                int mid = a + (b - a) / 2;
                if (valid[mid] <= ql) {
                    a = mid + 1;
                    j = mid;
                }
                else {
                    b = mid - 1;
                }
            }
            res[idx] = (long long)(j-ql+2) * (j-ql+1) / 2 + cumsum[qr+1] - cumsum[j+1];
        }
        return res;
    }
};
