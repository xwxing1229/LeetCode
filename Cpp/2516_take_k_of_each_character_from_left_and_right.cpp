// https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/

class Solution {
public:
    int takeCharacters(string s, int k) {
        // Find a substr with the maximum length that contains at most cnts_max[k]
        // for the kth char, where k = 0, 1, 2 corresponds to 'a', 'b', and 'c'.
        vector<int> cnts_max(3, -k);
        for (char ch: s) {
            cnts_max[ch - 'a'] += 1;
        }
        if (cnts_max[0] < 0 || cnts_max[1] < 0 || cnts_max[2] < 0) {
            return -1;
        }

        int left = 0, n = s.size();
        int res = n;
        vector<int> cnts(3, 0);
        for (int right = 0; right < n; ++right) {
            char ch = s[right];
            cnts[ch - 'a'] += 1;
            while (left <= right) {
                if (cnts[0] <= cnts_max[0] && cnts[1] <= cnts_max[1] && cnts[2] <= cnts_max[2]) {
                    res = min(res, n-(right-left+1));
                    break;
                }
                ch = s[left];
                cnts[ch - 'a'] -= 1;
                left += 1;
            }
        }
        return res;
    }
};
