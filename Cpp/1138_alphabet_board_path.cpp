// https://leetcode.cn/problems/alphabet-board-path/

class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        char pre = 'a';
        int pre_row = 0, pre_col = 0;
        for (char ch: target) {
            int ch_row = (ch - 'a') / 5, ch_col = (ch - 'a') % 5;
            int drow = ch_row - pre_row, dcol = ch_col - pre_col;
            string res_row, res_col;
            if (drow > 0) {
                res_row += string (drow, 'D');
            }
            else if (drow < 0) {
                res_row += string (-drow, 'U');
            }
            if (dcol > 0) {
                res_col += string (dcol, 'R');
            }
            else if (dcol < 0) {
                res_col += string (-dcol, 'L');
            }

            if (ch == 'z' && pre != 'z') {
                string res_row_z(drow-1, 'D');
                res += (res_row_z + res_col + "D!");
            }
            else {
                res += (res_row + res_col + '!');
            }

            pre = ch;
            pre_row = ch_row;
            pre_col = ch_col;
        }
        return res;
    }
};
