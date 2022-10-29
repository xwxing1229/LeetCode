// https://leetcode.cn/problems/sum-of-subarray-minimums/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long> dp(n);
        vector<int> st; // save indices s.t. arr[st[i]] <= arr[st[j]]
        long res = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            while ((!st.empty()) && (arr[st.back()] > arr[i])) {
                st.pop_back();
            }

            if (st.empty()) {
                cnt = i + 1;
            }
            else {
                cnt = i - st.back();
            }
            dp[i] = cnt * arr[i];
            if (!st.empty()) {
                dp[i] += dp[st.back()];
            }

            st.push_back(i);

            res = (res + dp[i]) % 1000000007;
        }
        return res;
    }
};
