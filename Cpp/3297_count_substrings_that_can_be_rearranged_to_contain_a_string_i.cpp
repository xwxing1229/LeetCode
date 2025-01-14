// https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        // unordered_map<char, int> cnt2;
        // for (auto ch: word2) cnt2[ch] += 1;

        // int n = word1.size();
        // vector<int> dp(n);
        // if (word2.size() == 1 && word1[0] == word2[0]) dp[0] = 1;
        // unordered_map<char, int> cnt1;
        // cnt1[word1[0]] += 1;
        // int left = 0;
        // for (int i = 1; i < n; ++i) {
        //     cnt1[word1[i]] += 1;
            
        //     bool valid = true;
        //     for (auto it = cnt2.begin(); it != cnt2.end(); ++it) {
        //         if (cnt1[it->first] < it->second) {
        //             valid = false;
        //             break;
        //         }
        //     }
        //     if (!valid) {
        //         dp[i] = dp[i-1];
        //         continue;
        //     }

        //     while (left < i) {
        //         char ch = word1[left];
        //         int tmp = cnt1[ch] - 1;
        //         if (tmp < cnt2[ch]) break;
        //         left += 1;
        //         cnt1[ch] = tmp;
        //     }
        //     dp[i] = left + 1;
        // }

        // long long res = 0;
        // for (auto val: dp) res += val;
        // return res;


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
