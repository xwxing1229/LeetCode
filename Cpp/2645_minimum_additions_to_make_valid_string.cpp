// https://leetcode.cn/problems/minimum-additions-to-make-valid-string/

class Solution {
public:
    int addMinimum(string word) {
        int res = 0;
        int i = 0, n = word.size();
        while (i < n) {
            char cur = word[i];
            if (cur == 'a') {
                i += 1;
                if (i < n && word[i] == 'b') {
                    i += 1;
                    if (i < n && word[i] == 'c') {
                        i += 1;
                    }
                    else {
                        res += 1;
                    }
                }
                else if (i < n && word[i] == 'c') {
                    res += 1;
                    i += 1;
                }
                else {
                    res += 2;
                }
            }
            else if (cur == 'b') {
                i += 1;
                if (i < n && word[i] == 'c') {
                    res += 1;
                    i += 1;
                }
                else {
                    res += 2;
                }
            }
            else {
                res += 2;
                i += 1;
            }
        }
        return res;
    }
};