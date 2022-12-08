// https://leetcode.cn/problems/determine-color-of-a-chessboard-square/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if ((coordinates[0] - 'a' + coordinates[1] - '0') % 2 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
