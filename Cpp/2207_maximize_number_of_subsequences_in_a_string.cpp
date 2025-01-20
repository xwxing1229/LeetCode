// https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int cnt1 = 0, cnt2 = 0;
        vector<pair<int, int>> cnts;
        for (char ch: text) {
            if (ch == pattern[0]) {
                if (cnt2 > 0) {
                    cnts.push_back(make_pair(cnt1, cnt2));
                    cnt1 = 1;
                    cnt2 = 0;
                }
                else {
                    cnt1 += 1;
                }
            }
            else if (ch == pattern[1]) {
                cnt2 += 1;
            }
        }
        cnts.push_back(make_pair(cnt1, cnt2));

        // Special case.
        if (pattern[0] == pattern[1]) {
            long long n = cnts[0].first;
            return (n+1)*n/2;
        }

        // Add pattern[0] at the beginning of text, or add pattern[1] at the end of text.
        long long tmp1 = 0, tmp2 = 0;
        long long cnt1_sum = 0, cnt2_sum = 0;
        for (int i = cnts.size()-1; i >= 0; --i) {
            cnt2_sum += cnts[i].second;
            tmp1 += cnt2_sum * cnts[i].first;
        }
        tmp1 += cnt2_sum;
        for (int i = 0; i < cnts.size(); ++i) {
            cnt1_sum += cnts[i].first;
            tmp2 += cnt1_sum * cnts[i].second;
        }
        tmp2 += cnt1_sum;
        return max(tmp1, tmp2);
    }
};
