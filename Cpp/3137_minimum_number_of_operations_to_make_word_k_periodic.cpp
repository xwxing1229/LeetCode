// https://leetcode.cn/problems/minimum-number-of-operations-to-make-word-k-periodic/

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> cnt;
        int n = word.size(), cnt_max = 0;
        for (int i = 0; i < n; i += k) {
            string sub = word.substr(i, k);
            cnt[sub] += 1;
            cnt_max = max(cnt_max, cnt[sub]);
        }
        return n / k - cnt_max;
    }
};
