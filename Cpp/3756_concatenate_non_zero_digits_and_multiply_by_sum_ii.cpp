// https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> pow10(int(1e5)+1, 1);
        for (int i = 1; i < 1e5+1; ++i) {
            pow10[i] = (long long)pow10[i-1] * 10 % mod;
        }

        int n = s.size();
        // cnt: number of non-zero digits
        vector<int> cumsum(n+1, 0), nums(n+1, 0), cnt(n+1, 0);
        for (int i = 0; i < n; ++i) {
            int val = s[i] - '0';
            cumsum[i+1] = cumsum[i] + val;
            nums[i+1] = val > 0 ? ((long long)nums[i] * 10 + val) % mod : nums[i];
            cnt[i+1] = cnt[i] + (val > 0);
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1] + 1;
            long long x = nums[r] - (long long)nums[l] * pow10[cnt[r] - cnt[l]] % mod + mod;
            res[i] = x * (cumsum[r] - cumsum[l]) % mod;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "10203004";
    vector<vector<int>> queries = {{0,7}, {1,3}, {4,6}};
    auto res = sol.sumAndMultiply(s, queries);
    for (const int val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}