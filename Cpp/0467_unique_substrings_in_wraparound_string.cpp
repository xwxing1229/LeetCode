// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // record[i]: maximum lenght of substring that ends with the ith letter.
        vector<int> record(26, 0);
        int n = 1;
        record[p[0] - 'a'] = n;
        for (int i = 1; i < p.size(); ++i) {
            if ((p[i] - p[i-1] == 1) || (p[i] - p[i-1] == -25)) {
                n += 1;
            }
            else {
                n = 1;
            }
            if (record[p[i] - 'a'] < n) {
                record[p[i] - 'a'] = n;
            }
        }

        int res = 0;
        for (int i: record) {
            res += i;
        }
        return res;
    }
};