// https://leetcode.cn/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        long base = 1;
        for (int i = columnTitle.size()-1; i >= 0; --i) {
            int tmp = columnTitle[i] - 'A' + 1;
            res = res + tmp * base;
            base = base * 26;
        }
        return res;
    }
};
