// https://leetcode.cn/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n-2; ++i) {
            vector<int> cnt(26, 0);
            int max_ = 0;
            for (int j = i; j < n; ++j) {
                int idx = s[j] - 'a';
                cnt[idx] += 1;
                if (max_ < cnt[idx]) {
                    max_ = cnt[idx];
                }
                int min_ = n;
                for (int val: cnt) {
                    if ((val > 0) && (val < min_)) {
                        min_ = val;
                    }
                }
                res += (max_ - min_);
            }
        }
        return res;
    }
};
