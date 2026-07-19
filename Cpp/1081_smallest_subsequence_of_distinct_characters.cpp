// https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a'] += 1;
        }

        string res;
        vector<bool> has(26, false);
        for (char ch: s) {
            int idx = ch - 'a';
            cnt[idx] -= 1;
            if (has[idx]) continue;
            while (!res.empty() && ch < res.back() && cnt[res.back() - 'a'] > 0) {
                has[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += ch;
            has[idx] = true;
        }
        return res;
    }
};