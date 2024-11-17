// https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0;
        int i = 0, n = s.size();
        vector<int> cnt(2, 0);
        for (int j = 0; j < n; ++j) {
            char ch = s[j];
            cnt[ch - '0'] += 1;
            while (cnt[0] > k && cnt[1] > k && i <= j) {
                cnt[s[i] - '0'] -= 1;
                i += 1;
            }
            res += j - i + 1;
        }
        return res;
    }
};
