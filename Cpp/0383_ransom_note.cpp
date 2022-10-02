// https://leetcode.cn/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n_ran = ransomNote.size(), n_mag = magazine.size();
        if (n_ran > n_mag) {
            return false;
        }

        vector<int> cnt_mag(26, 0);
        for (char c: magazine) {
            cnt_mag[c - 'a'] = cnt_mag[c - 'a'] + 1;
        }
        for (char c: ransomNote) {
            cnt_mag[c - 'a'] = cnt_mag[c - 'a'] - 1;
            if (cnt_mag[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
