// https://leetcode.cn/problems/reconstruct-original-digits-from-english/

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> statistic;
        for (char ch: s) {
            statistic[ch] = statistic[ch] + 1;
        }
        vector<int> cnt(10, 0);
        cnt[0] = statistic['z'];
        cnt[2] = statistic['w'];
        cnt[4] = statistic['u'];
        cnt[6] = statistic['x'];
        cnt[8] = statistic['g'];
        cnt[3] = statistic['h'] - cnt[8];
        cnt[5] = statistic['f'] - cnt[4];
        cnt[7] = statistic['v'] - cnt[5];
        cnt[1] = statistic['o'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = statistic['i'] - cnt[5] - cnt[6] - cnt[8];

        string res;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                // res = res + char(i + '0');
                res += char(i + '0'); // much faster
            }
        }
        return res;
    }
};
