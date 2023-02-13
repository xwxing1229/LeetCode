// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> cnt;
        for (char ch: s) {
            cnt[ch] += 1;
        }
        int n = s.size(), thr = n / 4;
        if (cnt['Q'] == thr && cnt['W'] == thr && cnt['E'] == thr && cnt['R'] == thr) {
            return 0;
        }

        int res = n, start = 0;
        for (int i = 0; i < n; ++i) {
            cnt[s[i]] -= 1;
            while (start <= i && cnt['Q'] <= thr && cnt['W'] <= thr && cnt['E'] <= thr && cnt['R'] <= thr) {
                res = min(res, i - start + 1);
                cnt[s[start]] += 1;
                start += 1;
            }
        }
        return res;
    }
};
