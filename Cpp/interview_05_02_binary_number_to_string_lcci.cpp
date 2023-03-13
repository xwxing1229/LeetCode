// https://leetcode.cn/problems/bianry-number-to-string-lcci/

class Solution {
public:
    string printBin(double num) {
        double num_new = num * pow(2, 6);
        int num_int = ceil(num_new);
        if (num_int != floor(num_new)) {
            return "ERROR";
        }

        string res;
        int digits = 0;
        while (num_int % 2 == 0) {
            num_int /= 2;
            digits += 1;
        }
        while (num_int > 0) {
            res = to_string(num_int % 2) + res;
            num_int /= 2;
            digits += 1;
        }
        res = "0." + string(6-digits, '0') + res;
        return res;
    }
};