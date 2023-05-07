// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        for (int t: time) {
            cnt[t%60] += 1;
        }
        long long res = (long long)cnt[0] * (cnt[0]-1) / 2
                        + (long long) cnt[30] * (cnt[30]-1) / 2;
        for (int i = 1; i < 30; ++i) {
            res += (long long)cnt[i] * cnt[60-i];
        }
        return (int)res;
    }
};