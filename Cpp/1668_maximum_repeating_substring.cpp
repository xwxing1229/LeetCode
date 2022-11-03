// https://leetcode.cn/problems/maximum-repeating-substring/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        /*
        int res = 0;
        int n_seq= sequence.size(), n_word = word.size();
        for (int i = 0; i <= n_seq - n_word; ++i) {
            int j = i, cnt = 0;
            while ((j <= n_seq - n_word) && (sequence.substr(j, n_word) == word)) {
                j += n_word;
                cnt += 1;
            }
            if (cnt > res) {
                res = cnt;
            }
        }
        return res;
        */

        // When the size of sequence is large, the following DP-based method should
        // be used.
        // dp[i]: maximum number of repeatitions of word in sequence.substr(0, i+len(word)).
        int res = 0;
        int n_seq = sequence.size(), n_word = word.size();
        vector<int> dp(n_seq, 0);
        for (int i = 0; i <= n_seq - n_word; ++i) {
            if (sequence.substr(i, n_word) == word) {
                dp[i] = 1;
                if (i >= n_word) {
                    dp[i] += dp[i - n_word];
                }
            }
            if (dp[i] > res) {
                res = dp[i];
            }
        }
        return res;
    }
};
