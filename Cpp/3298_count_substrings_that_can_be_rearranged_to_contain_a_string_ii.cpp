// https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> cnt2(26, 0);
        for (auto ch: word2) cnt2[ch - 'a'] += 1;

        int n = word1.size(), left = 0, pre = 0;
        long long res = 0;
        vector<int> cnt1(26, 0);
        for (int i = 0; i < n; ++i) {
            cnt1[word1[i] - 'a'] += 1;
            
            bool valid = true;
            for (int k = 0; k < 26; ++k) {
                if (cnt1[k] < cnt2[k]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                res += pre;
                continue;
            }

            while (left < i) {
                int idx = word1[left] - 'a';
                int tmp = cnt1[idx] - 1;
                if (tmp < cnt2[idx]) break;
                left += 1;
                cnt1[idx] = tmp;
            }
            pre = left + 1;
            res += pre;
        }

        return res;
    }
};
