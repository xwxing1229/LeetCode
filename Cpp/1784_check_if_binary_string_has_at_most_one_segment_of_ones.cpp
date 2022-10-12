// https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool start_to_check_1 = false;
        for (char ch: s) {
            if (ch == '0') {
                start_to_check_1 = true;
            }
            else if (start_to_check_1) {
                return false;
            }
        }
        return true;
    }
};
