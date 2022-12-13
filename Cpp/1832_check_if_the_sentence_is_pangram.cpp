// https://leetcode.cn/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnt(26,0);
        for (char ch: sentence) {
            cnt[ch - 'a'] = 1;
        }
        bool res = true;
        for (int i: cnt) {
            if (i != 1) {
                res = false;
                break;
            }
        }
        return res;
    }
};
