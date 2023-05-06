// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int res = 0, free = 0;
        string s = "croak";
        unordered_map<char, int> cnt;
        for (char ch: s) {
            cnt[ch] = 0;
        }
        for (char ch: croakOfFrogs) {
            cnt[ch] += 1;
            if (ch == 'c') {
                if (free == 0) res += 1;
                else free -= 1;
            }
            else if (ch == 'k') {
                free += 1;
            }
            else {
                int c = cnt[ch];
                for (char cur: s) {
                    if (cur == ch) break;
                    else if (cnt[cur] < c) return -1;
                }
            }
        }
        int c = cnt['c'];
        for (char cur: s) {
            if (cnt[cur] != c) return -1;
        }
        return res;
    }
};