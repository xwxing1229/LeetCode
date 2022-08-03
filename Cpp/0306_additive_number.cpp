// https://leetcode.cn/problems/additive-number/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        res = false;
        int n = num.size();
        for (int idx2 = 1; idx2 <= n/3*2; ++idx2) {
            for (int idx3 = idx2+1; idx3 < n; ++idx3) {
                backtrack(num, 0, idx2, idx3, false);
                if (res) {
                    return res;
                }
            }
        }
        return res;
    }

private:
    void backtrack(string num, int idx1, int idx2, int idx3, bool flag) {
        int n = num.size();
        if (idx3 == n) {
            if (flag) {
                res = true;
            }
            return;
        }

        int len1 = idx2 - idx1, len2 = idx3 - idx2;
        int len3 = max(len1, len2);
        string num1 = num.substr(idx1, len1), num2 = num.substr(idx2, len2);
        for (int i = len3; i < len3+2; ++i) {
            if (idx3 + i > n) {
                break;
            }
            string num3 = num.substr(idx3, i);
            if (isSum(num1, num2, num3)) {
                backtrack(num, idx2, idx3, idx3+i, true);
            }
        }
    }

    bool isSum(string num1, string num2, string num3) {
        // Check if num1 + num2 is equal to num3, where num1, num2 and num3 are
        // expressed using string.

        int n1 = num1.size(), n2 = num2.size(), n3 = num3.size();
        if ((n3 < n1) || (n3 < n2)) {
            return false;
        }
        if (((n1 > 1) && (num1[0] == '0')) || ((n2 > 1) && (num2[0] == '0')) ||
            ((n3 > 1) && (num3[0] == '0'))) {
            return false;
        }
        
        string com1(n3-n1, '0'), com2(n3-n2, '0');
        num1 = com1 + num1;
        num2 = com2 + num2;
        int carry = 0;
        for (int i = n3-1; i >= 0; --i) {
            int tmp = num1[i] - '0' + num2[i] - '0' + carry;
            if (tmp % 10 != num3[i] - '0') {
                return false;
            }
            carry = tmp / 10;
        }
        return true;
    }

    bool res;
};
