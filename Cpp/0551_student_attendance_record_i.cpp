// https://leetcode.cn/problems/student-attendance-record-i/

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0;
        for (char ch: s) {
            if (ch == 'A') {
                absent += 1;
                late = 0;
                if (absent >= 2) {
                    return false;
                }
            }
            else if (ch == 'L') {
                late += 1;
                if (late >= 3) {
                    return false;
                }
            }
            else {
                late = 0;
            }
        }
        return true;
    }
};
