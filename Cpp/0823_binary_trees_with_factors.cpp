// https://leetcode.cn/problems/binary-trees-with-factors/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), mod = 1000000007;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> idxs;
        vector<long> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            int j = 0, root = sqrt(val);
            while (j < i && arr[j] <= root) {
                if (val % arr[j] != 0 || idxs.find(val/arr[j]) == idxs.end()) {
                    ;
                }
                else if (arr[j] * arr[j] == val) {
                    dp[i] = (dp[i] + (dp[j] % mod) * (dp[idxs[val/arr[j]]] % mod)) % mod;
                }
                else {
                    dp[i] = (dp[i] + (dp[j] % mod) * (dp[idxs[val/arr[j]]] % mod) * 2) % mod;
                }
                j += 1;
            }
            idxs[val] = i;
        }
        int res = 0;
        for (auto cnt: dp) {
            res = (cnt + res) % mod;
        }
        return res;
    }
};
