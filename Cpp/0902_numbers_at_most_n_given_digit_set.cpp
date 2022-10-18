// https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int n_d = digits.size(), n_n = s.size();
        int res = 0, power = 1;
        vector<int> powers = {1};
        // Count number of numbers whose sizes are less than n_n.
        for (int i = 0; i < n_n-1; ++i) {
            power *= n_d;
            res += power;
            powers.push_back(power);
        }
        // Count number of numbers whose sizes are equal to n_n and that
        // are less than n.
        for (int i = 0; i < n_n; ++i) {
            bool same = false;
            for (string digit: digits) {
                if (s[i] > digit[0]) {
                    res += powers[n_n-1-i];
                }
                else if (s[i] == digit[0]) {
                    same = true;
                    break;
                }
                else {
                    break;
                }
            }
            if (!same) {
                return res;
            }
        }
        return res + 1;
    }
};
