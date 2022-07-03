// https://leetcode.cn/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        string alp = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int quo = columnNumber, rem = 0;
        while (columnNumber > 26) {
            quo = columnNumber / 26;
            rem = columnNumber - 26 * quo;
            columnNumber = quo;
            res = alp[rem] + res;
            if (rem == 0) {
                columnNumber = columnNumber - 1;
            }
        }
        res = alp[columnNumber] + res;
        return res;
    }
};
