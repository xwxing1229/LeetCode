// https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for (int k = 1; k < n; ++k) {
            if (n % k != 0) continue;

            bool valid = true;
            unordered_map<char, int> cnts;
            for (int i = 0; i < k; ++i) {
                cnts[s[i]] += 1;
            }
            for (int idx = k; idx < n; idx+=k) {
                unordered_map<char, int> cnts_tmp;
                for (int i = idx; i < idx+k; ++i) {
                    cnts_tmp[s[i]] += 1;
                }
                if (cnts != cnts_tmp) {
                    valid = false;
                    break;
                }
            }
            if (valid) return k;
        }
        return n;
    }
};