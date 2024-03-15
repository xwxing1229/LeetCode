// https://leetcode.cn/problems/capitalize-the-title/

class Solution {
public:
    string capitalizeTitle(string title) {
        int start = 0, n = title.size();
        string res(n, ' ');
        for (int i = 0; i < n; ++i) {
            char ch = title[i];
            if (ch == ' ') {
                if (i - start > 2) {
                    res[start] = toupper(res[start]);
                }
                start = i + 1;
            }
            else {
                res[i] = tolower(ch);
            }
        }
        if (n - start > 2) {
            res[start] = toupper(res[start]);
        }
        return res;
    }
};